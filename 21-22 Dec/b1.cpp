#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e5+10;
int next_L[maxn], next_R[maxn];
int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    int h_pos = 0, g_pos = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'G') {
            next_R[g_pos] = i + 1;
            next_L[i+1] = g_pos;
            g_pos = i+1;
        }else if (s[i] == 'H') {
            next_R[h_pos] = i + 1;
            next_L[i+1] = h_pos;
            h_pos = i+1;
        }
    }
    next_R[h_pos] = N+1;
    next_R[g_pos] = N+1;
    long long res = 0;
    for (int i = 1; i <= s.length(); ++i) {
        long long len_L = i - next_L[i] - 1;
        long long len_R = next_R[i] - i - 1;
//        cout << len_R << ' ' << len_L << endl;
        res += len_L * len_R;
        res += max(0LL, len_L - 1);
        res += max(0LL, len_R - 1);
    }
    cout << res << endl;
}
