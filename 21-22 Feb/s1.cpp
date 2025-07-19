#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> a[N];
int vis[N], tot = 0, n, con[N];
bool dfs(int u)
{
    if (vis[u] == tot)
    {
        return false;
    }
    vis[u] = tot;
    for (int x : a[u])
    {
        int v = x + n;
        if (vis[v] != tot)
        {
            vis[v] = tot;
            if (con[v] == 0 || dfs(con[v]))
            {
                con[u] = v;
                con[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
        while (a[i].size() && a[i].back() != i)
            a[i].pop_back();
    }
    for (int x = 1; x <= n; x++)
    {
        for (int i = 1; i <= n; i++)
        {
            int x = i + n;
            int y = i;
            con[y] = x;
            con[x] = y;
        }

        con[x] = 10;
        con[x + n] = 10;
        while (con[x])
            con[x]--;
        while (con[x + n])
            con[x + n]--;
        tot++;
        dfs(x);
        //assert(dfs(x));
        cout << con[x] - n << endl;
    }
    return 0;
}
/*
4
1 2 3 4
1 3 2 4
1 2 3 4
1 2 3 4

1
3
2
4
*/
