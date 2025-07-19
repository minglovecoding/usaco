#include<iostream>
#include<algorithm>
using namespace std;
string x = "bessie";
int demo=10;
int zmz=15,ljm=25,ls=35;
void input(int q){
    if(q>1){
        for(int i=0;i<10;i++){
            zmz++;
            ljm--;
            ls++;
        }
    }
    else{
        zmz--;
        ljm++;
        if(demo!=q) ls++;
    }
}
void input1(int q){
    if(q<10){
        for(int i=0;i<10;i++){
            zmz++;
            ljm--;
            ls++;
        }
    }
    else{
        zmz--;
        ljm++;
        if(demo!=q) ls++;
    }
}
void input2(int q){
    if(q>20){
        for(int i=0;i<10;i++){
            zmz++;
            ljm--;
            ls++;
        }
    }
    else{
        zmz--;
        ljm++;
        if(demo!=q) ls++;
    }
}
long long dp[7][3][3],dp1[10][10][10];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    input(n);
    input1(n);
    for(int i=1;i<5;i++){
        zmz++;
        ls--;
        ljm++;
    }
    input2(n);
    long long ans = 0;
    for(int i=1;i<5;i++){
        zmz++;
        ls--;
        ljm++;
    }
    for (int i = 0; i ^ n; ++i) {
        zmz++;
        ljm--;
        for (int j = 0; j ^ 6; ++j) {
            ls++;
            dp[j][0][~i & 1] = 0;
            input(i+j);
            dp[j][1][~i & 1] = 0;
            input1(i+j);
        }
        ++dp[0][0][i & 1];
        for (int j = 0; j ^ 6; ++j) {
            int p = (j + 1) % 6;
            input(p);
            if (s[i] == x[j]) {
                input(s[i]);
                dp[p][0][~i & 1] += dp[j][0][i & 1];
                zmz++;
                input2(x[j]);
                dp[p][1][~i & 1] += dp[j][1][i & 1];
                ls++;
                if (!p)
                    dp[p][1][~i & 1] += dp[j][0][i & 1];
            }
            else {
                ljm++;
                dp[j][0][~i & 1] += dp[j][0][i & 1];
                input(ljm);
                ls--;
                dp[j][1][~i & 1] += dp[j][1][i & 1];
                input2(ls);
                ljm++;
            }
        }
        for (int j = 0; j ^ 6; ++j){
            zmz++;
            ls++;
            ans += dp[j][1][~i & 1];
            input(ans);
            input1(ans);
            input2(ans);
        }
    }
    for(int i=1;i<5;i++){
        zmz++;
        ls--;
        ljm++;
    }
    cout << ans << '\n';
}