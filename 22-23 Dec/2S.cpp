#include <bits/stdc++.h>
using namespace std;

int n, h[100005], primes[500005], tot;
bool not_prime[5000005];
int dp[5000005];
vector<int> a{1}, b;

int F(int n) {
    if (n % 2 == 0) return n / 2;
    if (n % 4 == 1) {
        int val = *--upper_bound(a.begin(), a.end(), n);
        return (n - val) / 2 + 1;
    } else {
        int val = *--upper_bound(b.begin(), b.end(), n);
        return (n - val) / 2 + 1;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 2; i <= 5000000; ++i) {
        if (!not_prime[i]) primes[++tot] = i;
        for (int j = 1; j <= tot && i * primes[j] <= 5000000; ++j) {
            not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 1; i <= tot; ++i) {
        if (primes[i] % 4 == 1) a.push_back(primes[i]);
        else b.push_back(primes[i]);
    }

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> h[i];

        pair<int, int> a{1e9, 0}, b{1e9, 0};
        for (int i = 1; i <= n; ++i) {
            if (h[i] % 4 == 0) b = min(b, {F(h[i]) + 1, i});
            else a = min(a, {F(h[i]), i});
        }

        cout << (a < b ? "Farmer John" : "Farmer Nhoj") << "\n";
    }


    return 0;
}