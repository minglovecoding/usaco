#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 44;
const int N = (1 << 20);
ll x[maxn], y[maxn];
int bin[N];
struct node
{
    ll x, y, z;
    bool operator==(const node &a) const
    {
        return x == a.x && y == a.y && z == a.z;
    }
} e[N], e2[N];
bool cmp(node b, node a)
{
    if (b.x != a.x)
        return b.x < a.x;
    else if (b.y != a.y)
        return b.y < a.y;
    return b.z < a.z;
}
int num = 0;
int cnt[N];
ll ans[44];
int main()
{
    for (int i = 1; i < N; i++)
    {
        bin[i] = bin[i >> 1] + (i & 1);
    }
    int n;
    cin >> n;
    ll sx, sy;
    cin >> sx >> sy;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    if (n == 1)
    {
        if (x[0] == sx && y[0] == sy)
        {
            puts("1");
            return 0;
        }

        puts("0");
        return 0;
    }
    int m = n / 2;
    for (int mask = 0; mask < (1 << m); ++mask)
    {
        ll cx = 0, cy = 0;
        for (int i = 0; i < m; i++)
            if (mask >> i & 1)
                cx += x[i], cy += y[i];
        e[num++] = (node){cx, cy, bin[mask]};
    }
    sort(e, e + num, cmp);
    int tot = 0;
    for (int i = 0; i < num; ++i)
    {
        int j = i;
        while (j + 1 < num && e[j + 1] == e[j])
            j++;
        e2[tot] = e[i];
        cnt[tot] = j - i + 1;
        i = j;
        tot++;
    }

    int t = n - m;
    for (int mask = 0; mask < (1 << t); ++mask)
    {
        ll cx = 0, cy = 0;
        for (int i = 0; i < t; i++)
            if (mask >> i & 1)
                cx += x[m + i], cy += y[m + i];
        cx = sx - cx, cy = sy - cy;
        int p1 = lower_bound(e2, e2 + tot, (node){cx, cy, 0},cmp) - e2;
        while (p1 < tot && e2[p1].x == cx && e2[p1].y == cy)
        {
            ans[e2[p1].z + bin[mask]] += cnt[p1];
            p1++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
