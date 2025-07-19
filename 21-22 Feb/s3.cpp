#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int pre[N], nxt[N], res[N], n, m, k;
int fnd(int fa[], int x);
bool solve();
vector<int> g[N];
vector<int> f;
void init();

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        if (solve())
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
int fnd(int fa[], int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    int fx = fnd(fa, fa[x]);
    fa[x] = fx;
    return fx;
}
void init()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        res[i] = 0;
        g[i].clear();
    }
    f.clear();
    f.push_back(0);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        f.push_back(x);
        res[f[i]]++;
        g[f[i]].push_back(i);
    }
    for (int i = 1; i <= m + 1; i++)
    {
        nxt[i] = pre[i] = i;
    }
}
bool solve()
{
    init();
    int l = 1, r = 0, sz = 0;
    int ok = 1;
    for (int up = 1; up <= n - k + 1; up++)
    {
        int down = up + k - 1;
        if (down <= n)
        {
            for (int pos : g[down])
            {
                if (pos <= r && pos >= l)
                {
                    sz--;
                    nxt[pos] = pos + 1;
                    pre[pos] = pos - 1;
                    res[down]--;
                }
            }
        }
        while (res[up])
        {
            while (sz < k)
            {
                int p = fnd(nxt, r + 1);
                if (p > m)
                {
                    p = fnd(pre, l - 1);
                    if (l)
                    {
                        l = p;
                        sz++;
                        if (f[l] >= up && f[l] <= down)
                        {
                            res[f[l]]--;
                            nxt[l] = l + 1;
                            pre[l] = l - 1;
                            sz--;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    r = p;
                    sz++;
                    if (f[r] >= up && f[r] <= down)
                    {
                        res[f[r]]--;
                        nxt[r] = r + 1;
                        pre[r] = r - 1;
                        sz--;
                    }
                }
            }
            if (sz >= k && res[up])
            {
                if (res[up] == 0 || fnd(nxt, r + 1) != m + 1)
                {
                    l = fnd(nxt, fnd(nxt, l) + 1);
                    sz--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (res[up])
        {
            ok = 0;
            break;
        }
    }
    return ok;
}
/*
6
5 5 1
1 2 3 4 5
5 5 1
1 2 3 5 4
5 5 1
1 2 4 5 3
5 5 2
1 2 4 5 3
3 10 2
1 3 2 1 3 2 1 3 2 1
3 10 1
1 3 2 1 3 2 1 3 2 1


YES
YES
NO
YES
YES
NO

*/
