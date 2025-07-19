#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;
typedef pair<int, int> pii;
#define endl "\n"

int cas;
int n, cas_type;
string s1, s2;

const int N = 3e5 + 100;
pii ans1[N], ans2[N];
int ans_n1, ans_n2;

string compress_s(string& s) {
    string ret;
    ret.reserve(s.length()); 
    for(int i = 0; i < s.length(); ++i) {
        if(i == 0 || (s[i] != s[i - 1])) {
            ret += s[i];
        }
    }
    return ret;
}


void solve(vector<string>s, vector<int>idxs, pii* ans, int &ans_n) {
    if(s[0].length() == s[1].length() && s[0].length() == 1) {
        return;
    }
    if(s[0].back() == s[1].back()) {
        if(s[1].length() > s[0].length()) {
            s[1].pop_back();
            ans[++ans_n] = {idxs[1], idxs[0]};
        }
        else {
            s[0].pop_back();
            ans[++ans_n] = {idxs[0], idxs[1]};
        }
    }
    if(s[0].length() == s[1].length() && s[0].length() == 1) {
        return;
    }
    int still_3 = 0;
    if(s[0].length() > 1) {
        if(s[1].back() != s[0][0]) {
            ans[++ans_n] = {idxs[1], 3};
            s[1].pop_back();
        }
        else {
            ans[++ans_n] = {idxs[0], 3};
            s[0].pop_back();
        }
        assert(s[0].length() >= 1);
        for(int i = (int)s[0].length() - 1; i >= 1; --i) {
            if(s[0][i] == s[1].back()) ans[++ans_n] = {idxs[0], idxs[1]};
            else ans[++ans_n] = {idxs[0], 3};
        }

        if(s[1].back() == s[0].back()) {
            ans[++ans_n] = {idxs[1], idxs[0]};
            s[1].pop_back();
            still_3 = 1;
            if(s[1].length() <= 1) {
                ans[++ans_n] = {3, idxs[1]};
                return ;
            }
        }
        else{
            ans[++ans_n] = {3, idxs[0]};
            if(s[1].length() <= 1) {
                return ;
            }
        }
    }
    
    if(!still_3) {
        ans[++ans_n] = {idxs[1], 3};
        s[1].pop_back();
    }
    for(int i = (int)s[1].length() - 1; i >= 1; --i) {
        if(s[0][0] == s[1][i]) ans[++ans_n] = {idxs[1], idxs[0]};
        else ans[++ans_n] = {idxs[1], 3};
    }

    if(s[1][0] == s[0][0]) {
        ans[++ans_n] = {idxs[1], idxs[0]};
        ans[++ans_n] = {3, idxs[1]};
    }
    else{
        ans[++ans_n] = {3, idxs[1]};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cas;
    while(cas--) {
        cin >> n >> cas_type;
        cin >> s1 >> s2;
        assert(s1.length() == n);
        assert(s2.length() == n);
        assert(n <= 100000);
        s1 = compress_s(s1); s2 = compress_s(s2);
        ans_n1 = ans_n2 = 0;
        solve(vector<string>{s1, s2}, vector<int>{1, 2}, ans1, ans_n1);
        solve(vector<string>{s2, s1}, vector<int>{2, 1}, ans2, ans_n2);
        cout << min(ans_n1, ans_n2) << endl;
        assert(ans_n1 < 2 * n + 100);
        assert(ans_n2 < 2 * n + 100);
        if(cas_type > 1) {
            if(ans_n1 == min(ans_n1, ans_n2)) {
                for(int i = 1; i <= ans_n1; ++i) {
                    cout << ans1[i].first << " " << ans1[i].second << endl;;
                }
            }
            else {
                for(int i = 1; i <= ans_n2; ++i) {
                    cout << ans2[i].first << " " << ans2[i].second << endl;;
                }
            }
        }
    }
    return 0;
}