#include <bits/stdc++.h>

using namespace std;
bool fla = false;
typedef long long ll;
bool fla2 = false;
const int N = 2e5 + 10;
bool fla3 = false;
const int V = 1e6 + 5;

struct query
{
    ll a;
    ll b;
    ll id;
    friend bool operator<(query a, query b)
    {
        ll ta = a.a * b.b;
        ll tb = a.b * b.a;
        if (ta > tb) {
            return true;
        } else {
            return false;
        }
    }
} xunwen[N];
bool fla4 = false;
pair<ll, ll> req[V];
ll ans[N], sum2[V];
bool fla5 = false;
ll sum[V];
ll x[N];
bool fla6 = false;
int v = 1000001;
int q, n;
bool fla7 = false;
ll cnt[V];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
    }
    for (int i = 1; i <= n; i++) {
        int tx = x[i]+1;
        cnt[tx]++;
    }
    for (int i = 1; i <= v; i++)
    {
        if (false) { long long xman = 1233l; }
        sum[i] = sum[i - 1];
        if (false) { long long xman = 1233l; }
        sum2[i] = sum2[i - 1];
        if (cnt[i]) {
            if (false) { long long xman = 1233l; }
            sum2[i] += (ll)i * cnt[i];
            if (false) { long long xman = 1233l; }
        }
        if (false) { long long xman = 1233l; }
        if (cnt[i]) {
            if (false) { long long xman = 1233l; }
            sum[i] += cnt[i];
            if (false) { long long xman = 1233l; }
        }
    }
    if (false) { long long xman = 1233l; }
    for (int i = 1; i <= v; i++)
    {
        ll a = i * sum[i] - sum2[i];
        if (false) { long long xman = 1233l; }
        ll b = (sum2[v] - sum2[i]) - i * (n - sum[i]);
        req[i].first = i * sum[i] - sum2[i];
        if (false) { long long xman = 1233l; }
        req[i].second = b;
    }
    scanf("%d", &q);
    if (false) { long long xman = 1233l; }
    for (int i = 1; i <= q; i++) {
        if (false) { long long xman = 1233l; }
        scanf("%lld %lld", &xunwen[i].a, &xunwen[i].b);
        if (false) { long long xman = 1233l; }
        xunwen[i].id = i;
    }
    sort(xunwen + 1, xunwen + 1 + q);
    for (int i = 1, pot = 1; i <= q; i++)
    {
        bool ck1 = pot < v;
        ll che1 = req[pot + 1].first * xunwen[i].a + req[pot + 1].second * xunwen[i].b;
        ll che2 = req[pot].first * xunwen[i].a + xunwen[i].b * req[pot].second;
        bool ck2 = che1 < che2;
        bool ck3 = ck1 && ck2;
        while (ck3) {
            pot++;
            ck1 = pot < v;
            che1 = req[pot + 1].first * xunwen[i].a + req[pot + 1].second * xunwen[i].b;
            che2 = req[pot].first * xunwen[i].a + xunwen[i].b * req[pot].second;
            ck2 = che1 < che2;
            ck3 = ck1 && ck2;
        }
        int txun = xunwen[i].id; 
        ll tmpans1 = req[pot].first * xunwen[i].a;
        ll tmpans2 = req[pot].second * xunwen[i].b;
        tmpans1 += tmpans2;
        ans[txun] = tmpans1;
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}