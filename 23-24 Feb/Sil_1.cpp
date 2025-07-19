#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <assert.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

const int N = 4e4 + 100;

int cas;
int n;
ll X1;
ll Y1[N], X2[N], Y2[N];
vector<ll>neg_book, pos_book;
vector<ll>book, Y_book;
ll max_y, min_y;


ll solve1() {
    sort(neg_book.begin(), neg_book.end());
    ll ansl = 1;
    ll ansr = 0x3f3f3f3f3f3f3f3f;
    while(ansl <= ansr) {
        ll ansm = (ansl + ansr) / 2;
        bool flag = true;
        multiset<ll>book;
        for(int i = (int)neg_book.size() - n; i < neg_book.size(); ++i)
            book.insert(neg_book[i]);
        for(int i = 1; i <= n; ++i) {
            if(ansm <= Y2[i]) {
                flag = false;
                break;
            }
            ll t = (ansm - Y2[i]) / X2[i];
            t = -t;
            auto it = book.lower_bound(t);
            if(it == book.end()) {
                flag = false;
                break;
            }
            book.erase(it);
        }
        if(flag) {
            ansr = ansm - 1;
        }
        else {
            ansl = ansm + 1;
        }
    }
    for(int i = 0; i < neg_book.size() - n; ++i) {
        book.push_back(neg_book[i]);
    }
    return ansl;
}

ll solve2() {
    sort(pos_book.begin(), pos_book.end());
    ll ansr = 0x3f3f3f3f3f3f3f3f;
    ll ansl = -ansr;
    while(ansl <= ansr) {
        ll ansm = (ansl + ansr) / 2;
        bool flag = true;
        multiset<ll>book;
        for(int i = 0; i < n; ++i)
            book.insert(pos_book[i]);
        for(int i = 1; i <= n; ++i) {
            if(ansm >= Y1[i]) {
                flag = false;
                break;
            }
            ll t = (Y1[i] - ansm) / X2[i] + ((Y1[i] - ansm) % X2[i] != 0);
            auto it = book.lower_bound(t);
            if(it == book.begin()) {
                flag = false;
                break;
            }
            --it;
            book.erase(it);
        }
        if(flag) {
            ansl = ansm + 1;
        }
        else {
            ansr = ansm - 1;
        }
    }
    for(int i = n; i < pos_book.size(); ++i) {
        book.push_back(pos_book[i]);
    }
    return ansr;
}

int main() {
    cin >> cas;
    while(cas--) {
        neg_book.clear(); pos_book.clear(); book.clear(); Y_book.clear();
        cin >> n >> X1;
        max_y = -0x3f3f3f3f3f3f3f3f;
        min_y = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i <= n; ++i) {
            cin >> Y1[i] >> Y2[i] >> X2[i];
            Y_book.push_back(Y1[i]);
            Y_book.push_back(Y2[i]);
        }
        for(int i = 1; i <= 4 * n; ++i) {
            ll s;
            cin >> s;
            assert(s != 0);
            if(s < 0) neg_book.push_back(s);
            if(s > 0) pos_book.push_back(s);
        }
        if(neg_book.size() < n || pos_book.size() < n) {
            cout << -1 << endl;
            continue;
        }
        min_y = min(min_y, solve1());
        max_y = max(max_y, solve2());
        
        assert(Y_book.size() == book.size());
        int m = 2 * n;
        assert(Y_book.size() == m);
        sort(Y_book.begin(), Y_book.end());
        sort(book.begin(), book.end());
        for(int i = 0; i < m; ++i) {
            ll now_y = Y_book[i];
            ll now_s = book[i];
            ll yy = now_y - now_s * X1;
            min_y = max(min_y, yy);
            max_y = min(max_y, yy);
        }
        cout << min_y - max_y - 1 << endl;
    }
    return 0;
}