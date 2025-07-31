#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int sum = 0;
    bool put = false;
    int val = 0;
 
    void apply(int l, int r, int v) {
      put = true;
      val = v;
      sum = v * (r - l + 1);
    }
  };
 
  node unite(const node &a, const node &b) const {
    node res;
    res.sum = max(a.sum, b.sum);
    return res;
  }
 
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].put) {
      tree[x + 1].apply(l, y, tree[x].val);
      tree[z].apply(y + 1, r, tree[x].val);
      tree[x].put = false;
    }
  }
 
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  int n;
  vector<node> tree;
 
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
 
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
 
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
 
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
 
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
 
  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
 
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
 
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
 
  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
 
};

void solve() {
    int n, q, C;
    cin >> n >> q >> C;
    vector<int> originalValues(n), updatedValues(n);
    segtree segTree(n);

    for (int i = 0; i < n; i++) {
        cin >> originalValues[i];
        updatedValues[i] = originalValues[i];
        segTree.modify(i, i, originalValues[i]);
    }

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        queries.push_back({x, y});
    }

    sort(queries.begin(), queries.end());

    if (originalValues[0] == 0) {
        originalValues[0] = 1;
        segTree.modify(0, 0, 1);
    }

    for (auto [l, r] : queries) {
        int leftSum = segTree.get(0, l).sum;
        int rightSum = segTree.get(0, r - 1).sum;
        int currentSum = segTree.get(0, r).sum;

        if (leftSum == currentSum) {
            if (originalValues[r]) {
                cout << -1 << '\n';
                return;
            }
            originalValues[r] = leftSum + 1;
            segTree.modify(r, r, leftSum + 1);
        }

        if (leftSum < rightSum) {
            for (int j = l; j >= 0; j--) {
                if (updatedValues[j] == 0) {
                    originalValues[j] = rightSum;
                    segTree.modify(j, j, rightSum);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (originalValues[i] == 0) {
            originalValues[i] = 1;
            segTree.modify(i, i, 1);
        }
    }

    if (*max_element(originalValues.begin(), originalValues.end()) > C) {
        cout << -1 << '\n';
        return;
    }

    for (auto [l, r] : queries) {
        int leftSum = segTree.get(0, l).sum;
        int rightSum = segTree.get(0, r - 1).sum;
        int currentSum = segTree.get(0, r).sum;

        if (leftSum == currentSum or leftSum < rightSum) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << originalValues[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}