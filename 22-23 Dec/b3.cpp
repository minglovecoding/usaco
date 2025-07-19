#include <bits/stdc++.h> 
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string st[101];
        int out[101];
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> st[i] >> out[i];
        }
        int make[101];
        memset(make, 0, sizeof(make));
        int f = 1, make_f = 1;
        while (1) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (make[i] != 0) {
                    cnt += 1;
                }
            }
            if (cnt == m) break;
            if (f == 0)break;
            make_f = 0;
            for (int i = 0; i < n; i++) {
                int mmp[2][2];
                mmp[0][0] = mmp[0][1] = mmp[1][0] = mmp[1][1] = 0;
                for (int j = 0; j < m; j++) {
                    if (make[j] != 0) continue;
                    mmp[st[j][i] - '0'][out[j]] += 1;
                }
                if (mmp[0][0] * mmp[0][1] == 0 && mmp[0][0] + mmp[0][1] > 0) {
                    for (int j = 0; j < m; j++) {
                        if (st[j][i] - '0' == 0) make[j] = 1;
                    }
                    make_f = 1;
                    break;
                }
                else if (mmp[1][0] * mmp[1][1] == 0 && mmp[1][0] + mmp[1][1] > 0) {
                    for (int j = 0; j < m; j++) {
                        if (st[j][i] - '0' == 1) {
                            make[j] = 1;
                        }
                    }
                    make_f = 1;
                    break;
                }
            }
            if (make_f == 0) f = 0;
        }
        if (f == 1) cout << "OK" << endl;
        else cout << "LIE" << endl;
    }
    return 0;
}