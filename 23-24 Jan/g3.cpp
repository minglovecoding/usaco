#include <iostream>
#include <vector>
#include <algorithm>

long long check(std::vector<long long> &a, long long k) {
    int n = a.size();
    int j = 0;
    int z;
    long long sum = 0;
    for (int i = k; i >= 1 && j < n; --i) {
        sum += i;
        z = j;
        while (j < n && a[j] <= sum)
            ++j;
        if (z == j ||(j - 1 < n && a[j - 1] != sum))
            ++j;
    }
    if (j < n)
        return a[n - 1];
    else
        return k * (k + 1) / 2;
}

long long solve(std::vector<long long> &a) {
    int n = a.size();
    std::sort(a.begin(), a.end());
    int l = 0;
    int r = n;
    while (l + 3 <= r) {
        int mid = (l + r) / 2;
        long long c = check(a, mid);
        if (c == a[n - 1])
            l = mid + 1;
        else
            r= mid;
    }
    long long ans = a[n - 1];
    for (int i = l; i <= r; ++i) {
        long long c = check(a, i);
        ans = std::min(ans, check(a, i));
    }
        return ans;
}


int main() {
//    freopen("123.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::vector<long long> a;
        for (int i = 0; i < n; ++i) {
            long long temp;
            scanf("%lld", &temp);
            a.push_back(temp);
        }
        printf("%lld\n", solve(a));
    }
}
