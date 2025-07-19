#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int P = 1e9 + 7;
void add(int &x, int y) {
    (x += y) >= P && (x -= P);
}
int Add(int x, int y) {
    return add(x, y), x;
}
void sub(int &x, int y) {
    (x -= y) < 0 && (x += P);
}
int Sub(int x, int y) {
    return sub(x, y), x;
}
void mul(int &x, int y) {
    x = 1ll * x * y % P;
}
int Mul(int x, int y) {
    return 1ll * x * y % P;
}
int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, mul(a, a)) {
        if (b & 1) {
            mul(res, a);
        }
    }
    return res;
}

const int N = 305;
int n, a[N], ans[N][N], q, bt[61], C[N][N], qaq[N]; 
i64 L, R;
int f[61][61][2][3], g[61][61][2][3];

void solve(i64 A, int coef) {
    int m = 0;
    while (A) {
        bt[m++] = A % 10;
        A /= 10;
    }
    memset(qaq, 0, sizeof qaq);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur = C[i][j];
            mul(cur, (1ll << j) % P);
            add(qaq[i], cur);
        }
    }
    for (int s = 1; s <= n; ++s) {
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= i; ++j) {
                memset(f[i][j], 0, sizeof f[i][j]);
            }
        }
        f[m][0][0][1] = 1;
        for (int t = s; t >= 1; --t) {
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= i; ++j) {
                    memcpy(g[i][j], f[i][j], sizeof g[i][j]);
                }
            }
            int val = a[t];
            for (int x = 1; x <= m; ++x) {
                bool valid = (val <= bt[x - 1]);
                bool tmp = (val < bt[x - 1]);
                for (int y = 0; y < x; ++y) {
                    for (int a = 0; a < 2; ++a) {
                        for (int b = 0; b < 3; ++b) {
                            if (!f[x][y][a][b]) continue;
                            add(g[x][y + 1][a][(val == bt[y]) ? b : (val > bt[y] ? 2 : 0)], f[x][y][a][b]);
                            if (valid) add(g[x - 1][y][a || tmp][b], f[x][y][a][b]);
                        }
                    }
                    if (!valid) {
                        for (int b = 0; b < 3; ++b) {
                            if (f[x][y][1][b]) {
                                add(g[x - 1][y][1][b], f[x][y][1][b]);
                            }
                        }
                    }
                }
            }
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= i; ++j) {
                    memcpy(f[i][j], g[i][j], sizeof f[i][j]);
                }
            }
            int sum = 0;
            for (int x = 0; x <= m; ++x) {
                add(sum, f[x][x][0][0]);
                add(sum, f[x][x][0][1]);
                add(sum, f[x][x][1][0]);
                add(sum, f[x][x][1][1]);
                add(sum, f[x][x][1][2]);
            }
            add(sum, qaq[s - t + 1]);
            (coef == 1 ? add : sub)(ans[t][s], sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> L >> R;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }

    solve(R, 1);
    solve(L - 1, -1);

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << "\n";
    }

    return 0;
}