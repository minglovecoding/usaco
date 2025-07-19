#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

char canvas[MAXN][MAXN], stamp[MAXN][MAXN], my[MAXN][MAXN];
int N, K;

void paint(int x, int y) {
    bool flag = true;
    for (int i = x; i < x + K; i++) {
        for (int j = y; j < y + K; j++) {
            if (canvas[i][j] == '.' && stamp[i - x][j - y] == '*') {
                flag = false;
            }
        }
    }
    if (flag) {
        for (int i = x; i < x + K; i++) {
            for (int j = y; j < y + K; j++) {
                if (my[i][j] == '.') {
                    my[i][j] = stamp[i - x][j - y];
                }
            }
        }
    }
}

void rotate() {
    char c[MAXN][MAXN];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[j][N - i - 1] = canvas[i][j];
        }
    }
    memcpy(canvas, c, sizeof(canvas));
    char m[MAXN][MAXN];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[j][N - i - 1] = my[i][j];
        }
    }
    memcpy(my, m, sizeof(my));
}

bool equal() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (canvas[i][j] != my[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> canvas[i];
        }
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> stamp[i];
        }
        for (int i = 0; i < N; i++) {
            memset(my[i], '.', sizeof(my[i]));
        }
        bool flag = false;
        for (int t = 0; t < 4; t++) {
            for (int i = 0; i < N - K + 1; i++) {
                for (int j = 0; j < N - K + 1; j++) {
                    paint(i, j);
                }
            }
            if (equal()) {
                flag = true;
                break;
            }
            rotate();
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
