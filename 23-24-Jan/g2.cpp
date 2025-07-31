#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cstring>
#include <assert.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1e6 + 100;
const int mod = 1e9 + 7;


ll n;
int Q, C;
ll Q_book[10005][2];
ll dp[1000][10005];
ll sum[1000][10005];
set<ll>point_book;
map<ll, int>point_rank;
map<int, ll>point_val;
int type[1000];
int b_mn[1000];




void lisanhua() {
    point_val[0] = 0;
    int tim = 0;
    for(ll x: point_book) {
        point_rank[x] = ++tim;
        point_val[tim] = x;
    }
}

void real_set(int idx, int set_type) {
    if(type[idx] == -1) {
        type[idx] = set_type;
        return;
    }
    if(type[idx] == 1) {
        type[idx] = set_type;
    }
    if(type[idx] == 2) {
        if(set_type == 3) {
            cout << 0 << endl;
            exit(0);
        }
        return;
    }
    if(type[idx] == 3) {
        if(set_type == 2) {
            cout << 0 << endl;
            exit(0);
        }
        return;
    }
}
void set_type() {
    memset(type, -1, sizeof(type));
    memset(b_mn, 0x3f, sizeof(b_mn));
    for(int i = 0; i < Q; ++i) {
        ll a = Q_book[i][0]; int a_idx = point_rank[a];
        ll b = Q_book[i][1] - 1; int b_idx = point_rank[b];
        ll c = Q_book[i][1]; int c_idx = point_rank[c];
        if(b == a) {
            real_set(a_idx, 1);
            real_set(c_idx, 3);
        }
        else {
            real_set(a_idx, 1);
            real_set(b_idx, 2);
            real_set(c_idx, 3);
            b_mn[b_idx] = min(b_mn[b_idx], a_idx);
        }
    }
}


ll quick_pow(ll x, ll n) {
    ll ret = 1;
    while(n) {
        if(n & 1) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int32_t main() {
    cin >> n >> Q >> C;
    for(int i = 0; i < Q; ++i) {
        cin >> Q_book[i][0] >> Q_book[i][1];
        point_book.insert(Q_book[i][0]);
        point_book.insert(Q_book[i][1]);
        point_book.insert(Q_book[i][1] - 1);
    }
    lisanhua();
    set_type();
    int m = (int)point_book.size();
    dp[0][0] = 1; sum[0][0] = 1;
    for(int j = 1; j <= C; ++j) sum[0][j] = sum[0][j - 1] + dp[0][j];
    for(int i = 1; i <= m; ++i) {
        assert(type[i] >= 1 && type[i] <= 3);
        if(type[i] == 1) {
            for(int j = 1; j <= C; ++j) {
                ll seg_len = point_val[i] - point_val[i - 1];
                ll o1 = (quick_pow(j, seg_len) - quick_pow(j - 1, seg_len));
                o1 = (o1 % mod + mod) % mod;
                o1 = sum[i - 1][j - 1] * o1 % mod;
                ll o2 = dp[i - 1][j] * quick_pow(j, seg_len) % mod;
                dp[i][j] = (o1 + o2) % mod;
            }
        }
        if(type[i] == 2) {
            for(int j = 1; j <= C; ++j) {
                ll seg_len = point_val[i] - point_val[b_mn[i]];
                ll o = quick_pow(j, seg_len);
                dp[i][j] = dp[b_mn[i]][j] * o % mod;
            }
        }
        if(type[i] == 3) {
            for(int j = 1; j <= C; ++j) {
                dp[i][j] = sum[i - 1][j - 1];
            }
        }
        for(int j = 1; j <= C; ++j) {
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
        }
    }
    assert(n >= point_val[m]);
    ll ans = sum[m][C] * quick_pow(C, (n - point_val[m])) % mod;
    assert(ans >= 0);
    cout << ans << endl;
    return 0;
}