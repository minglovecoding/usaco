#include <bits/stdc++.h>

using namespace std;

const int N = 777;

char get01char() {
	char ch = getchar();
	while (ch != '0'&&ch != '1') ch = getchar();
	return ch;
}

int a[N][N], b[N][N], f[N], n, ans;

int main() {
	// freopen("a.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			a[i][j] = (get01char() == '1');
	for (int i = n; i >= 1; i--) {
		f[i] = 1;
		for (int j = i + 1; j <= n; j++) f[j] = 0;
		for (int j = i + 1; j <= n; j++) {
			for (int k = i + 1; k < j; k++)
				if (b[k][j]) f[j] ^= f[k];
			if (f[j] != a[i][j])
				b[i][j] = 1, f[j] ^= 1;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = n; j > i; j--)
			ans += b[i][j];
	cout << ans << endl;
	return 0;
}