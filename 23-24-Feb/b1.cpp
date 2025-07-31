#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <assert.h>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 2e5 + 100;

int cas;
int main() {

    cin >> cas;
    while(cas--) {
        string s;
        cin >> s;
        if(s[s.length() - 1] == '0') {
            cout << "E" << endl;
        }
        else {
            cout << "B" << endl;
        }
    }
    return 0;
}