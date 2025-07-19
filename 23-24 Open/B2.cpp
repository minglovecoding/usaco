#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <utility> // For std::pair

using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int> > a(p);
    for (int i = 0; i < p; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    
    int totalPerimeter = 0;
    for (int i = 0; i < p; ++i) {
        int next = (i + 1) % p;
        totalPerimeter += manhattanDistance(a[i].first, a[i].second, a[next].first, a[next].second);
    }

    vector<pair<int, int> > c;
    for (int i = 0; i < p; ++i) {
        c.push_back(a[i]);
        int x1 = a[i].first, y1 = a[i].second;
        int x2 = a[(i + 1) % p].first, y2 = a[(i + 1) % p].second;
        if (x1 == x2) {
            if (y1 < y2) {
                for (int j = y1 + 1; j < y2; ++j) {
                    c.push_back({x1, j});
                }
            } else {
                for (int j = y1 - 1; j > y2; --j) {
                    c.push_back({x1, j});
                }
            }
        } else {
            if (x1 < x2) {
                for (int j = x1 + 1; j < x2; ++j) {
                    c.push_back({j, y1});
                }
            } else {
                for (int j = x1 - 1; j > x2; --j) {
                    c.push_back({j, y1});
                }
            }
        }
    }

    a = c;
    p = a.size();
    
    map<pair<int, int>, int> id;
    for (int i = 0; i < p; ++i) {
        id[a[i]] = i;
    }

    a.insert(a.end(), a.begin(), a.end());
    vector<int> b(p+1, 0);
    
    for (int i = 0; i < p+2; ++i) {
        b[i] = abs(a[i].first - a[i + 1].first) + abs(a[i].second - a[i + 1].second);
    }
    
    for (int i = 1; i < p+2; ++i) {
        b[i] += b[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = id[{x1, y1}];
        int y = id[{x2, y2}];
        if (x > y) swap(x, y);
        int d1 = b[y] - b[x];
        int d2 = totalPerimeter - d1;
        cout << min(d1, d2) << endl;
    }

    return 0;
}