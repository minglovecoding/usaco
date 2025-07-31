#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cstring>
#include <assert.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const int N = 2e5 + 100;

ll n;
ll a[N];
ll times = 0;
ll ans = 0;
ll tot = 0;
ll base;
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        
        tot += base;
        
        a[i] = a[i] + tot;
        
        ans += abs(a[i]);
        
        base = base - a[i];
        tot += -a[i];
    }
    cout << ans << endl;
    return 0;
}