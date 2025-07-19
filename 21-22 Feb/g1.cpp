#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
int cas, n;
int arr[100000 + 10], prefix[100000 + 10];
unordered_set<int>my_set;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
}

void init() {
    my_set.clear();
    for(int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i];
        my_set.insert(prefix[i]);
    }
}

int solve() {
    if(prefix[n] == 0) {
        return 0;
    }
    for(int i = 1; i <= 1000000; ++i) {
        if(prefix[n] % i != 0) {
            continue;
        }
        int c = prefix[n] / i;
        int flag = 1;
        for(int j = 1; j <= c; ++j) {
            int x = j * i;
            if(my_set.count(x) == 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            return n - c;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> cas;
    for(int _ = 0; _ < cas; ++_) {
        read();
        init();
        cout << solve() << endl;
    }
    return 0;
}