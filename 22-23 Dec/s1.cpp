#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, cnt = 0;

vector<int> vec[N];
ll siz[N], sum[N], a[N];
ll avg = 0;
struct node
{
    int x, y;
    ll z;
} q[N];
void dfs(int x, int Fa)
{
    siz[x] = 1;
    sum[x] = a[x];
    for (int v : vec[x])
    {
        if (v == Fa)
            continue;
        dfs(v, x);
        sum[x] += sum[v];
        siz[x] += siz[v];
    }
    if (sum[x] > avg * siz[x])
    {
        q[++cnt].x = x, q[cnt].y = Fa, q[cnt].z = sum[x] - avg * siz[x];
        sum[Fa] += (sum[x] - avg * siz[x]);
        sum[x] = avg * siz[x];
    }
}
void dfs2(int x, int Fa)
{
    for (int v : vec[x])
    {
        if (v == Fa)
            continue;
        if (sum[v] >= siz[v] * avg)
        {
            dfs2(v, x);
        }
        else
        {
            q[++cnt].x = x, q[cnt].y = v, q[cnt].z = avg * siz[v] - sum[v];
            sum[v] += avg * siz[v] - sum[v];
            sum[x] -= (avg * siz[v] - sum[v]);
            dfs2(v, x);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n * 1ll;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    printf("%lld\n", cnt);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%lld %lld %lld\n", q[i].x, q[i].y, q[i].z);
    }
    return 0;
}
