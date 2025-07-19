#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;
const int N = 100005;
typedef long long ll;
int T, n;
ll c_time, m_time;
ll a[N], b[N], c[N];

ll find_bottom_c(int i, ll ans) {
    ll ans_l = 0;
    ll ans_r = min(c_time - 1, ans);
    ll sum = a[i]*c_time+b[i]*m_time;
    while(ans_l <= ans_r) {
        ll ans_m = (ans_l + ans_r) / 2;
        if(sum - ans_m * a[i] - min((ans - ans_m), m_time - 1) * b[i] - c[i] <= 0) {
            ans_r = ans_m - 1;
        }
        else {
            ans_l = ans_m + 1;
        }
    }
    return ans_l;
}
ll find_bottom_m(int i, ll ans) {
    ll ans_l = 0;
    ll ans_r = min(m_time - 1, ans);
    ll sum = a[i]*c_time+b[i]*m_time;
    while(ans_l <= ans_r) {
        ll ans_m = (ans_l + ans_r) / 2;
        if(sum - ans_m * b[i] - min((ans - ans_m), c_time - 1) * a[i] - c[i] <= 0) {
            ans_r = ans_m - 1;
        }
        else {
            ans_l = ans_m + 1;
        }
    }
    return ans_l;
}

bool check(ll ans) {
    ll bottom_c = 0;
    ll bottom_m = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] >= b[i]) {
            bottom_c = max(bottom_c, find_bottom_c(i, ans));
        }
        if(b[i] >= a[i]){
            bottom_m = max(bottom_m, find_bottom_m(i, ans));
        }
    }
    if(bottom_c > ans || bottom_c > c_time - 1) {
        return false;
    }
    if(bottom_m > ans || bottom_m > m_time - 1) {
        return false;
    }
    return bottom_c + bottom_m <= ans;
}

ll solve() {
    ll ans_l = 0;
    ll ans_r = c_time + m_time - 2;
    while(ans_l <= ans_r) {
        ll ans_m = (ans_l + ans_r) / 2;
        if(check(ans_m)) {
            ans_r = ans_m - 1;
        }
        else {
            ans_l = ans_m + 1;
        }
    }
    return ans_l;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> c_time >> m_time;
        for(int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
/*
 2
 3 7 9
 4 3 18
 2 4 19
 1 1 6

 5 7 3
 5 9 45
 5 2 31
 6 4 28
 4 1 8
 5 2 22



 100

 3 2 2
 100 300 400
 100 300 500
 200 300 500

 1 2 2
 100 300 400

 1 2 1
 100 300 400

 1 2 1
 100 300 500
 */