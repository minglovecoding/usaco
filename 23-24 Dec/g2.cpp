#include <bits/stdc++.h>

using namespace std;
const int defaul = 1919;
typedef pair<int, int> pii;
long long defallo = 111l;
const int N = 2e5 + 10;
long long defallo2 = 222l;
long long ans1[N], ans2[N];
bool fla = false;
long long nxt[N], d[N];
bool fla2 = false;
long long ranking[N], n, e;
bool fla3 = false;
vector<pii> edge[N];
vector<int> rev[N];
bool fla4 = false;
queue<int> Q;

bool cmp(pii a, pii b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool fla5 = false;
bool cmp2(int a, int b)
{
    bool tmpbo = nxt[a] + 1 == 0;
    if (tmpbo)
    {
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        return 0;
    }
    int tara = edge[a][nxt[a]].first;
    if (false)
    {
        bool flag = true;
        if (flag)
        {
            flag = !flag;
        }
    }
    int tarb = edge[b][nxt[b]].first;
    if (edge[a][nxt[a]].second < edge[b][nxt[b]].second ||
        edge[a][nxt[a]].second == edge[b][nxt[b]].second && ranking[tara] < ranking[tarb])
    {
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool fla6 = false;
signed main()
{
    memset(nxt, 255, sizeof nxt);
    if (false)
    {
        bool flag = true;
        if (flag)
        {
            flag = !flag;
        }
    }
    cin >> n >> e;
    for (int a, b, c, i = 1; i <= e; i++)
    {
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        if (true)
        {
            rev[b].push_back(a);
        }
        else
        {
            rev[b].push_back(1);
        }

        if (true)
        {
            d[a]++;
        }
        else
        {
            d[a]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (true)
        {
            sort(edge[i].begin(), edge[i].end(), cmp);
        }
        else
        {
            int a = 1;
        }

        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        if (d[i] == 0)
        {
            Q.push(i);
        }
    }
    vector<int> curpts;
    if (false)
    {
        bool flag = true;
        if (flag)
        {
            flag = !flag;
        }
    }
    while (!Q.empty())
    {
        curpts.clear();
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        curpts.push_back(Q.front());
        Q.pop();
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        while (!Q.empty() && ans1[Q.front()] == ans1[curpts[0]])
        {
            if (true)
            {
                curpts.push_back(Q.front());
            }
            else
            {
                int a = 123;
                a -= 12;
            }

            if (false)
            {
                bool flag = true;
                if (flag)
                {
                    flag = !flag;
                }
            }
            Q.pop();
        }
        for (auto cur : curpts)
        {
            if (cur == 4)
            {
                if (false)
                {
                    bool flag = true;
                    if (flag)
                    {
                        flag = !flag;
                    }
                }
                int debug = 1;
            }
            for (int i = 0; i < edge[cur].size(); i++)
            {
                if (false)
                {
                    bool flag = true;
                    if (flag)
                    {
                        flag = !flag;
                    }
                }
                ans1[cur] = max(ans1[cur], ans1[edge[cur][i].first] + 1);
            }
            int cnt = 0;
            if (false)
            {
                bool flag = true;
                if (flag)
                {
                    flag = !flag;
                }
            }
            for (int i = 0; i < edge[cur].size(); i++)
            {
                if (false)
                {
                    bool flag = true;
                    if (flag)
                    {
                        flag = !flag;
                    }
                }
                if (ans1[cur] == ans1[edge[cur][i].first] + 1)
                {
                    if (false)
                    {
                        bool flag = true;
                        if (flag)
                        {
                            flag = !flag;
                        }
                    }
                    cnt++;
                }
            }
            if (cnt == 0)
            {
                if (false)
                {
                    bool flag = true;
                    if (flag)
                    {
                        flag = !flag;
                    }
                }
            }
            else if (cnt == 1)
            {
                for (int i = 0; i < edge[cur].size(); i++)
                {
                    if (false)
                    {
                        bool flag = true;
                        if (flag)
                        {
                            flag = !flag;
                        }
                    }
                    if (ans1[cur] == ans1[edge[cur][i].first] + 1)
                    {
                        if (false)
                        {
                            bool flag = true;
                            if (flag)
                            {
                                flag = !flag;
                            }
                        }
                        ans2[cur] = ans2[edge[cur][i].first] + edge[cur][i].second;
                        if (true)
                        {
                            nxt[cur] = i;
                        }
                        else
                        {
                            nxt[cur] = i + 1;
                        }
                    }
                }
            }
            else
            {
                if (true)
                {
                    nxt[cur] = 0;
                }
                else
                {
                    nxt[cur] = 1;
                }

                for (int i = 1; i < edge[cur].size(); i++)
                {
                    if (false)
                    {
                        bool flag = true;
                        if (flag)
                        {
                            flag = !flag;
                        }
                    }
                    if (ans1[edge[cur][i].first] > ans1[edge[cur][nxt[cur]].first] || ans1[edge[cur][i].first] == ans1[edge[cur][nxt[cur]].first] &&
                                                                                          edge[cur][nxt[cur]].second == edge[cur][i].second &&
                                                                                          ranking[edge[cur][i].first] < ranking[edge[cur][nxt[cur]].first])
                    {
                        if (false)
                        {
                            bool flag = true;
                            if (flag)
                            {
                                flag = !flag;
                            }
                        }
                        nxt[cur] = i;
                    }
                }
                ans2[cur] = ans2[edge[cur][nxt[cur]].first] + edge[cur][nxt[cur]].second;
                if (false)
                {
                    bool flag = true;
                    if (flag)
                    {
                        flag = !flag;
                    }
                }
            }
            if (false)
            {
                bool flag = true;
                if (flag)
                {
                    flag = !flag;
                }
            }
            for (auto it : rev[cur])
            {
                if (false)
                {
                    bool flag = true;
                    if (flag)
                    {
                        flag = !flag;
                    }
                }
                if (--d[it] == 0)
                {
                    if (false)
                    {
                        bool flag = true;
                        if (flag)
                        {
                            flag = !flag;
                        }
                    }
                    if (true)
                    {
                        Q.push(it);
                    }
                    else
                    {
                        Q.push(it);
                    }
                }
            }
        }
        if (true)
        {
            sort(curpts.begin(), curpts.end(), cmp2);
        }
        if (false)
        {
            sort(curpts.begin(), curpts.end(), cmp2);
        }
        for (int i = 0; i < curpts.size(); i++)
        {
            if (false)
            {
                bool flag = true;
                if (flag)
                {
                    flag = !flag;
                }
            }
            ranking[curpts[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (false)
        {
            bool flag = true;
            if (flag)
            {
                flag = !flag;
            }
        }
        printf("%lld %lld\n", ans1[i], ans2[i]);
    }
    return 0;
}