#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll powarr[100];
ll sfun(ll a, ll b) {
 
 //init_start
 
 powarr[0] = 1;
 for(int i = 1; i < 64; ++ i){
 powarr[i] = powarr[i - 1] * 2;
 }
 
 //init_end
 
 if(a == b) return 0;
 int cnt = 0;
 ll ans = 0;
 
 while(b >= 2 * a) {
 a = a * 2;
 ans += 1;
 cnt += 1;
 }
 
 ll cha = b - a;
 for(int i = cnt; i >= 0; --i) {
 ans += cha / powarr[i];
 cha %= powarr[i];
 }
 
 return ans;
}
ll solfun(ll a, ll b) {
 
 ll prog = LLONG_MAX;
 ll ans = 0;
 if(a <= b) {
 prog = min(ans + sfun(a, b), prog);
 }
 while(a != 1) {
 if(a % 2 == 1) {
 a += 1;
 ans += 1;
 if(a <= b) {
 prog = min(ans + sfun(a, b), prog);
 }
 }
 a /= 2;
 ans += 1;
 if(a <= b) {
 prog = min(ans + sfun(a, b), prog);
 }
 }
 return prog;
}
int main() {
 
 int T;
 cin >> T;
 while(T--) {
 ll a, b;
 cin >> a >> b;
 cout << solfun(a, b) << endl;
 }
 return 0;
 
}