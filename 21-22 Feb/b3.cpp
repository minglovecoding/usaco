#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int n;
unordered_set<char>book[4];
string blocks[4];

bool check(string s) {
    int len = (int)s.length();
    vector<int>a;
    for(int i = 0; i < 4; ++i) {
        a.push_back(i);
    }
    bool ok = false;
    do{
        bool flag = true;
        for(int i = 0; i < len; ++i) {
            flag &= (book[a[i]].count(s[i]));
        }
        ok |= flag;
    }while(next_permutation(a.begin(), a.end()));
    return ok;
}

void read() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < 4; ++i) {
        cin >> blocks[i];
    }
}

void init() {
    for(int i = 0; i < 4; ++i) {
        for(char c : blocks[i]) {
            book[i].insert(c);
        }
    }
}

int main() {
    read();
    init();
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << (check(s) ? "YES" : "NO") << endl;
    }
    return 0;
}