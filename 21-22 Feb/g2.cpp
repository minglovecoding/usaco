#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 1010;
double c[N][N], p[N], sp[N], bp[N];
int n, m, k = 1;

void read() {
    cin >> n >> m;
    n -= 1;
}

void prepare_C() {
    for(int i = 0; i <= n; ++i) {
        c[i][i] = c[i][0] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

void prepare_array() {
    for(int i = 0; i <= n; ++i) {
        p[i] = pow(0.5, n) * c[n][i];
    }
    sp[0] = p[0];
    for(int i = 1; i <= n; ++i) {
        sp[i] = sp[i - 1] + p[i];
    }
    for(int i = n; i >= 0; --i) {
        bp[i] = bp[i + 1] + p[i] * i;
    }
}
double solve() {
    double cur = 0;
    for(int i = 1; i <= m; ++i) {
        cur = sp[k - 1] * cur + bp[k];
        k = ceil(cur);
        if(i >= 100) {
            double B = cur - bp[k] / (1 - sp[k - 1]);
            double T = k - bp[k] / (1 - sp[k - 1]);
            T /= B;
            int t = log(T) / log(sp[k - 1]) - 1;
            if(t <= 5) {
                continue;
            }
            
            t = min(t, m - i);
            i += t;
            cur = bp[k] / (1 - sp[k - 1]) + B * pow(sp[k - 1], t);
            k = ceil(cur);
        }
    }
    return cur + 1;
}

int main() {
    read();
    prepare_C();
    prepare_array();
    printf("%.10lf\n", solve());
    return 0;
}