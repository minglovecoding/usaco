#include <bits/stdc++.h>
using namespace std;

using std::cin;
using std::cout;
using std::set;
using i64 = long long;

constexpr int MAX_N = 1e6 + 5;
int stringLength, modValue;
bool currentParity;
i64 totalSteps;

class ModuloComparator {
public:
    bool operator()(int lhs, int rhs) const {
        int modLeft = lhs % modValue, modRight = rhs % modValue;
        if (modLeft == modRight) {
            return lhs < rhs;
        }
        return modLeft < modRight;
    }
};

set<int, ModuloComparator> modSortedPositions; 

void solve() {
    cin >> stringLength >> modValue;

    string initialString, targetString;
    cin >> initialString >> targetString;

    for (int i = 0; i < stringLength; ++i) {
        initialString[i] ^= '0';
        targetString[i] ^= '0';
    }

    for (int i = 0; i < stringLength; ++i) {
        if (initialString[i] != targetString[i]) {

            if (initialString[i] == currentParity || modSortedPositions.empty()) {
                modSortedPositions.insert(i); 
                currentParity = initialString[i]; 
            } else {
             
                auto closestPosition = modSortedPositions.lower_bound(i % modValue);
                if (closestPosition == modSortedPositions.end()) {
                    closestPosition = modSortedPositions.begin();
                }
            
                totalSteps += (i - *closestPosition - 1) / modValue + 1;
                modSortedPositions.erase(closestPosition); 
            }
        }
    }
    cout << totalSteps << '\n'; 
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;
    
    while (testCases--) {
        solve();
    }

    return 0;
}