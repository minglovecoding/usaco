#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int x;

int check(vector<int> a, vector<int> b) {
    int cnt = 0, cnt2 = 0;
    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            if(a[i] > b[j]) cnt++;
            else if(a[i] < b[j]) cnt2++;
        }
    }
    if(cnt == cnt2) return 0;
    if(cnt > cnt2) return 1;
    else return -1;
}

void check2(vector<int> a, vector<int> b) {
    vector<int> c;
    for(int i = 0;i < 4;i++)    c.push_back(0);
    for(int i = 1;i < 11;i++) {
        for(int j = 1;j < 11;j++) {
            for(int k = 1;k < 11;k++) {
                for(int l = 1;l < 11;l++) {
                    c[0] = i; c[1] = j; c[2] = k; c[3] = l;
                    if(check(b, c) == 1 && check(c, a) == 1) {
                        cout << "yes\n"; 
                        return ;
                    }
                }
            }
        }
    }
    cout << "no\n";
    return ;
}

int main() {
    vector<int> a, b;
    cin >> t;
    while(t--) {
        a.clear();  b.clear();
        for(int i = 0;i < 4;i++) {
            cin >> x;
            a.push_back(x);
        }
        for(int i = 0;i < 4;i++) {
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int fla = check(a, b);
        if(fla == 0) {
            cout << "no\n";
        } else {
            if(fla == -1) swap(a, b);
            check2(a, b);
        }
    }
    
    return 0;
}

