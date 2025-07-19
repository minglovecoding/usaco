#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    long long arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    long long ans = K + 1;

    for (int i = 1; i < N; i++) {
        long long distance = arr[i] - arr[i - 1];
        if (distance <= K + 1) {
            ans += distance;
        } else {
            ans += K + 1;
        }
    }

    cout << ans << endl;

    return 0;
}