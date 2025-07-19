#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> cows(N);
    vector<int> canes(M);

    for (int i = 0; i < N; ++i) {
        cin >> cows[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> canes[i];
    }

    for (int i = 0; i < M; ++i) {
        long long low = 0;
        long long high = canes[i];

        for (int j = 0; j < N; ++j) {
            if (cows[j] > high) {     // eat entire canes
                cows[j] += high - low;
                break;
            }

            if (cows[j] > low) {      // eat part of canes
                long long temp = cows[j];
                cows[j] += cows[j] - low;
                low = temp;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << cows[i] << endl;
    }

    return 0;
}
