#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define N 1000005
#define M 1000005
#define INF 2000000000
struct edge {
	int des, next, w;
}e[2 * M];
queue<int>q;
int n, m, s, t, u, v, w, cnt = -1, head[N], depth[N], cur[N];
int a[N], b[N], mp[N], rd[N], vis[N];
vector<int>G[N];
void ins(int u, int v, int w) {
	e[++cnt].next = head[u]; e[cnt].des = v; e[cnt].w = w; head[u] = cnt;
	e[++cnt].next = head[v]; e[cnt].des = u; e[cnt].w = 0; head[v] = cnt;
}
int dfs(int u, int flow) {
	if (u == t) return flow;
	for (int i = cur[u]; i != -1; i = e[i].next) {
		cur[u] = e[i].next;
		int v = e[i].des;
		if (depth[v] == depth[u] + 1 && e[i].w > 0) {
			int di = dfs(v, min(flow, e[i].w));
			if (di > 0) {
				e[i].w -= di;
				e[i ^ 1].w += di;
				return di;
			}
		}
	}
	return 0;
}
bool bfs() {
	memset(depth, 0, sizeof(depth));
	depth[s] = 1;
	q.push(s);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = e[i].next) {
			v = e[i].des;
			if (depth[v] == 0 && e[i].w > 0) {
				depth[v] = depth[u] + 1;
				q.push(v);
			}
		}
	}
	if (depth[t]) return true;
	return false;
}
int id[N];
bool vis1[N];
vector<int> stk;
void fi_dfs(int u) {
	cout << u << endl;
	vis[u] = 1;
	for (int v : G[u]) {
		if (vis1[v]) continue;
		if (!vis[v]) {
			fi_dfs(v);
		}
	}
}
void gettar(int now, int x) {
	id[now] = x;
	stk.push_back(now);
	vis[now] = 1;
	for (auto to : G[now]) {
		if (!vis[to]) gettar(to, x);
		else {
			if (id[to] == x) {
				for (int i = stk.size() - 1; i >= 0; i--) {
					vis1[stk[i]] = 1;
					cout << stk[i] << endl;
					if (stk[i] == to) break;
				}
			}
		}
	}
	stk.pop_back();
}
void topo() {
	queue<int>q;
	for (int i = 1; i <= n; ++i) {
		if (vis1[i]) continue;
		if (rd[i] == 0) {
			q.push(i);
			vis[i] = 1;
		}
	}
	vector<int>buf;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		buf.push_back(u);
		for (int v : G[u]) {
			if (vis1[v]) continue;
			if (--rd[v] == 0) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (vis1[i]) continue;
		if (!vis[i]) {
			fi_dfs(i);
		}
	}
	for (auto o : buf) {
		cout << o << endl;
	}

}
int main() {
	memset(head, -1, sizeof(head));
	cin >> n >> m;
	s = n + m + 1;
	t = n + m + 2;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		ins(s, i, 1);
		ins(i, a[i] + n, 1);
		ins(i, b[i] + n, 1);

	}
	for (int i = 1; i <= m; ++i) {
		ins(i + n, t, 1);
	}
	int ans = 0;
	while (bfs()) {
		for (int i = 1; i <= n + m + 2; ++i) cur[i] = head[i];
		while (int d = dfs(s, INF)) ans += d;
	}
	cout << n - ans << endl;

	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j != -1; j = e[j].next) {
			int v = e[j].des;
			if (e[j].w == 0) {
				// cout << i << " " << v - n << endl;
				mp[v - n] = i;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j != -1; j = e[j].next) {
			int v = e[j].des;
			if (e[j].w == 0) {
				if (v - n == b[i] && mp[a[i]]) {
					// cout << "! " << mp[a[i]] << " " << i << endl;
					G[mp[a[i]]].push_back(i);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			gettar(i, i);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (vis1[i]) continue;
		for (auto to : G[i]) {
			if (vis1[to]) continue;
			++rd[to];
		}
	}
	topo();
	return 0;
}