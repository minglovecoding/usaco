#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += a[i];
        int left = i == 0 ? s.length() - 1 : i - 1;
        int right = i == s.length() - 1 ? 0 : i + 1;
        if(s[left] == 'R' && s[i] == 'L' && s[right] == 'L'){
            int j = right;
            long minute = m;
            while(s[j] == 'L' && minute > 0) {
                sum -= min(minute, a[j]);
                minute -= min(minute, a[j]);
                j = j == s.length() - 1 ? 0 : j + 1;
            }
        }
        else if(s[left] == 'R' && s[i] == 'R' && s[right] == 'L'){
            int j = left;
            long minute = m;
            while(s[j] == 'R' && minute > 0) {
                sum -= min(minute, a[j]);
                minute -= min(minute, a[j]);
                j = j == 0 ? s.length() - 1 : j - 1;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
