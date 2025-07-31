#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    vector<ll> d(n + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        sum += a[i];
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
    }
    for (int i = n; i < 2 * n; i++) {
        while (q.size() && q.front() < i - n) q.pop_front();
        if (a[i] > a[i - 1]) {
            q.push_back(i);
        } else {
            while (q.size() && a[q.back()] > a[i]) {
                int delta = a[q.back()] - a[i];
                d[i - q.back()] -= delta;
                q.pop_back();
                if (q.size()) {
                    d[i - q.back()] += delta;
                }
            }
            q.push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
    }
    
    for (int i = 1; i <= n; i++) {
        sum += d[i];
        cout << sum << "\n";
    }
    return 0;
}