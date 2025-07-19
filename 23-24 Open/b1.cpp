#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> lastor(n, -1), lastf(n, -1), nxtor(n, n), nxtf(n, n);
    int x = -1, y = -1, z = 0, cur = 1;
    vector<int> l(n, 0);
    for (int i = 0; i < n; ++i) {
        lastor[i] = x;
        lastf[i] = y;
        if (s[i] == "or") {
            x = i;
            if (cur == 1) {
                z = 1;
            }
            l[i] = z;
            cur = 1;
        }
        if (s[i] == "false") {
            y = i;
            cur = 0;
        }
    }

    x = n;
    y = n;
    z = 0;
    cur = 1;
    vector<int> r(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        nxtor[i] = x;
        nxtf[i] = y;
        if (s[i] == "or") {
            x = i;
            if (cur == 1) {
                z = 1;
            }
            r[i] = z;
            cur = 1;
        }
        if (s[i] == "false") {
            y = i;
            cur = 0;
        }
    }

    string out = "";
    for (int i = 0; i < m; ++i) {
        int u, v;
        string w;
        cin >> u >> v >> w;
        --u;
        --v;
        int ans = 0;
        int x = 0;
        if (w == "true") {
            ans = 1;
            x = 1;
        }
        if (lastf[u] > lastor[u]) {
            x = 0;
        }
        if (nxtf[v] < nxtor[v]) {
            x = 0;
        }
        if (lastor[u] >= 0) {
            x |= l[lastor[u]];
        }
        if (nxtor[v] < n) {
            x |= r[nxtor[v]];
        }
        if (x == ans) {
            out += 'Y';
        }
        else {
            out += 'N';
        }
    }
    cout << out << endl;

    return 0;
}
