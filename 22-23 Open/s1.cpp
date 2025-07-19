#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long a[150001], b[150001], pre[150001], suf[150002], suf1[150002];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + b[i] * i;
	for (int i = n; i; --i)
		suf[i] = suf[i + 1] + b[i] * (i - 1);
	for (int i = n; i; --i)
		suf1[i] = suf1[i + 1] + b[i] * (i + 1);
	cin >> q;
	for (; q--;) {
		int p;
		long long x;
		cin >> p >> x;
		int v = lower_bound(b + 1, b + 1 + n, a[p]) - b;
		int u = lower_bound(b + 1, b + 1 + n, x) - b;
		long long ans = pre[min(v - 1, u - 1)];
		if (v < u) {
			ans += suf[v + 1] - suf[u];
			ans += x * (u - 1);
			ans += pre[n] - pre[u - 1];
		}
		else {
			ans += pre[n] - pre[v];
			ans += suf1[u] - suf1[v];
			ans += x * u;
		}
		cout << ans << '\n';
	}
}