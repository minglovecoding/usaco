#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> hay(N);

        for (int i = 0; i < N; i++) {
            cin >> hay[i];
        }

        set<int> haySet;

        for (int i = 0; i < N - 1; i++) {
            if (hay[i] == hay[i + 1]) {
                haySet.insert(hay[i]);
            }
            if (i < N - 2 && hay[i] == hay[i + 2]) {
                haySet.insert(hay[i]);
            }
        }

        if (haySet.empty()) {
            cout << -1 << endl;
            continue;
        }

        vector<int> hayList(haySet.begin(), haySet.end());
        sort(hayList.begin(), hayList.end());

        for (int i = 0; i < hayList.size() - 1; i++) {
            cout << hayList[i] << " ";
        }

        cout << hayList.back() << endl;
    }

    return 0;
}
