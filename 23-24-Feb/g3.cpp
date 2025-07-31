
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using TP = tuple<ll, ll, ll>;
void solve() {
    int n;
    cin >> n;
    vector<ll> p(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto calc = [&](ll x, ll y) {
        ll d = p[y] - p[x];
        if (x % 2 == 0) {

            return (d + s[x] + s[y] - 1) / (s[x] + s[y]) * 2 - 1;
        } else {
            return (d + s[x] + s[y] - 1) / (s[x] + s[y]) * 2;
        }
    };

    priority_queue<TP, vector<TP>, greater<TP>> q;

    vector<int> l(n), r(n);
    vector<ll> del(n);
    for (int i = 0; i < n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
        if (i + 1 < n) {
            q.push(make_tuple(calc(i, i + 1), i, i + 1));
        }
    }

    while (q.size()) {
        auto [t, x, y] = q.top();
        q.pop();

        if (del[x] != 0 || del[y] != 0) {
            continue;
        }
        del[x] = del[y] = t;


        if (l[x] != -1 && r[y] != n) {
            q.push(make_tuple(calc(l[x], r[y]), l[x], r[y]));
        }


        if (l[x] != -1) {
            r[l[x]] = r[y];
        }
        if (r[y] != n) {
            l[r[y]] = l[x];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << del[i];
        if(i!=n-1){
            cout<<" ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}