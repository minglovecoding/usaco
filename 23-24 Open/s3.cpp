#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> cnt(n + 3, vector<int>(n + 3, 0));
    vector<vector<int>> last(n + 1, vector<int>(n + 1, -10));
    vector<vector<int>> val(n + 1, vector<int>(n + 1, -10));

    int c1;

    for (int L = 1; L <= n; L++) {
        vector<int> a;

        for (int i = 0; i < n - L + 1; i++) {
            a.push_back(i);
        }

        auto f = [&](int i, int j) {
            if (last[i][j]==L-1){
                if (val[i][j]==2){
                    last[i][j]=L;
                    val[i][j]=2;
                    return 2;
                }
                if(val[i][j]==0){
                    last[i][j]=L;
                    val[i][j]=0;
                    return 0;
                }
                if (s[i+L-1]>s[j+L-1]) {
                    last[i][j]=L;
                    val[i][j]=2;
                    return 2;
                }
                if (s[i+L-1]<s[j+L-1]) {
                    last[i][j]=L;
                    val[i][j]=0;
                    return 0;
                }
                last[i][j]=L;
                val[i][j]=1;
                return 1;
            }
            for(int k=0;k<L;k++){
                if (s[i+k]>s[j+k]) {
                    last[i][j]=L;
                    val[i][j]=2;
                    return 2;
                }
                else if (s[i+k]<s[j+k]) {
                    last[i][j]=L;
                    val[i][j]=0;
                    return 0;
                }
            }
            last[i][j]=L;
            val[i][j]=1;

            return 1;
        };

        vector<int> stack1;
        vector<int> l(n - L + 1, -1);
        for (int i = 0; i < n - L + 1; i++) {
            while (!stack1.empty() && f(stack1.back(), a[i]) == 2) {
                int i1=stack1.back();
                int j1=a[i];

                stack1.pop_back();
            }
            l[i] = !stack1.empty() ? stack1.back() : -1;
            stack1.push_back(i);
        }

        stack1.clear();
        vector<int> r(n - L + 1, -1);
        for (int i = n - L; i >= 0; i--) {
            while (!stack1.empty() && f(stack1.back(), a[i]) >= 1) {
                stack1.pop_back();
            }
            r[i] = !stack1.empty() ? stack1.back() : n - L + 1;
            stack1.push_back(i);
        }

        for (int i = 0; i < n - L + 1; i++) {
            cnt[L][L]++;
            cnt[L+r[i]-l[i]-1][L]--;
        }
    }

    vector<int> ans(n + 1, 0);
    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans[cnt[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }


    return 0;
}