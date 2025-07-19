#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    string s;
    vector<int>pairs;
    cin >> n >> s;
    vector<vector<int>>dp(n, vector<int>(2, 0));
    for(int i = 0; i < n; i += 2) {
        if(s[i] == 'G' && s[i + 1] == 'H') {
            pairs.push_back(0);
        }
        if(s[i] == 'H' && s[i + 1] == 'G') {
            pairs.push_back(1);
        }
    }
    dp[0][pairs[0]] = 0;
    dp[0][pairs[0] ^ 1] = 1;
    int m = (int)(pairs.size());
    for(int i = 1; i < m; ++i) {
        for(int j = 0; j < 2; ++j) {
            dp[i][pairs[i]] = dp[i - 1][pairs[i]];
            dp[i][pairs[i] ^ 1] = dp[i - 1][pairs[i]] + 1;
            dp[i][pairs[i]] = min(dp[i][pairs[i]], dp[i][pairs[i] ^ 1] + 1);
            dp[i][pairs[i] ^ 1] = min(dp[i][pairs[i] ^ 1], dp[i][pairs[i]] + 1);
        }
    }
    cout << dp[m - 1][1] << endl;
    return 0;
}