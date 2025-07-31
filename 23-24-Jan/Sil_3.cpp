#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int result = 0;
    unordered_set<int> uniqueNumbers(numbers.begin(), numbers.end());
    int mx = *min_element(uniqueNumbers.begin(), uniqueNumbers.end()) / 4;

    if (uniqueNumbers.size() <= 3) {
        cout << mx * (mx + 1) / 2 << endl;
        return 0;
    }

    for (int i = 1; i <= 1000000; ++i) {
        if (i > mx) break;
        unordered_set<int> moduloSet;
        for (int num : uniqueNumbers) {
            moduloSet.insert(num % i);
            if (moduloSet.size() == 4) {
                break;
            }
        }
        if (moduloSet.size() < 4) {
            result += i;
        }
    }

    if (uniqueNumbers.size() < 1000) {
        unordered_set<int> factorSet;
        for (int num1 : uniqueNumbers) {
            for (int num2 : uniqueNumbers) {
                if (num2 - num1 > 1000000) {
                    for (int k = 1; k <= 4000; ++k) {
                        if ((num2 - num1) % k == 0) {
                            factorSet.insert((num2 - num1) / k);
                        }
                    }
                }
            }
        }

        for (int factor : factorSet) {
            if (factor > mx) continue;
            if (factor <= 1000000) continue;
            unordered_set<int> moduloSet;
            for (int num : uniqueNumbers) {
                moduloSet.insert(num % factor);
                if (moduloSet.size() == 4) {
                    break;
                }
            }
            if (moduloSet.size() < 4) {
                result += factor;
            }
        }
    }

    cout << result << endl;

    return 0;
}