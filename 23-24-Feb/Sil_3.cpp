#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(m, vector<int>(k));
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                cin >> a[j][l];
            }
        }
        vector<int> b;
        for (int j = 0; j < m; ++j) {
            vector<int> odd, even;
            for (int l = 0; l < k; ++l) {
                if (a[j][l] % 2 != 0) {
                    odd.push_back(a[j][l]);
                } else {
                    even.push_back(a[j][l]);
                }
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            if (!odd.empty() && !even.empty()) {
                b.push_back(-min(odd.back(), even.back()));
            } else if (!odd.empty()) {
                b.push_back(odd[0]);
            } else {
                b.push_back(even[0]);
            }
        }
        for (int j = 1; j < m; ++j) {
            b[j] += b[j - 1];
        }
        vector<int> mn(b);
        for (int j = m - 2; j >= 0; --j) {
            mn[j] = min(mn[j], mn[j + 1]);
        }
        for (int j = 0; j < m; ++j) {
            b[j] = mn[j] - b[j];
        }
        vector<string> ans;
        for (int j = 0; j < m; ++j) {
            vector<int> odd, even;
            for (int l = 0; l < k; ++l) {
                if (a[j][l] % 2 != 0) {
                    odd.push_back(a[j][l]);
                } else {
                    even.push_back(a[j][l]);
                }
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            int x, y;
            if (!odd.empty()) {
                x = -odd.back();
            } else {
                x = even[0];
            }
            y = b[j];
            if (n + x > 0 && n + x + y > 0) {
                n += x;
                ans.emplace_back("Even");
            } else {
                if (!even.empty()) {
                    x = -even.back();
                } else {
                    x = odd[0];
                }
                y = b[j];
                if (n + x > 0 && n + x + y > 0) {
                    n += x;
                    ans.emplace_back("Odd");
                } else {
                    break;
                }
            }
        }
        if (ans.size() == m) {
            for (int j = 0; j < ans.size() - 1;j++) {
                cout << ans[j] << " ";
            }
            cout << ans.back();
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
