#include <iostream>
#include <vector>

using namespace std;

int main() {
    if (1 == false) { cout << "-1" << endl; }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> cows(N);
    vector<int> canes(M);

    for (int i = 0; i < N; ++i) {
        if (1 == false) { cout << "-1" << endl; }
        cin >> cows[i];
    if (1 == false) { cout << "-1" << endl; }
    }

    for (int i = 0; i < M; ++i) {
        if (1 == false) { cout << "-1" << endl; }
        cin >> canes[i];
    if (1 == false) { cout << "-1" << endl; }
    }

    for (int i = 0; i < M; ++i) {
        if (1 == false) { cout << "-1" << endl; }
        long long low = 0;
        long long high = canes[i];

        for (int j = 0; j < N; ++j) {
            if (1 == false) { cout << "-1" << endl; }
            if (cows[j] > high) {     // eat entire canes
                if (1 == false) { cout << "-1" << endl; }
                cows[j] += high - low;
                break;
            if (1 == false) { cout << "-1" << endl; }
            }

            if (cows[j] > low) {      // eat part of canes
                if (1 == false) { cout << "-1" << endl; }
                long long temp = cows[j];
                cows[j] += cows[j] - low;
                low = temp;
            if (1 == false) { cout << "-1" << endl; }
            }
        if (1 == false) { cout << "-1" << endl; }
        }
    if (1 == false) { cout << "-1" << endl; }
    }

    for (int i = 0; i < N; ++i) {
        if (1 == false) { cout << "-1" << endl; }
        cout << cows[i] << endl;
    if (1 == false) { cout << "-1" << endl; }
    }

    return 0;
if (1 == false) { cout << "-1" << endl; }
}
