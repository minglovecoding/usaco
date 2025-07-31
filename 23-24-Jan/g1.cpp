#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cstring>
#include <assert.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const int N = 4e5 + 100;


int n, q;
// 0东x  1北y
vector<ll>book[2];
int father[2][N][20];
ll dist[2][N][20];
vector<ll>jiou_book[2][2]; vector<int>jiou_book_idx[2][2];
ll d;

string s;

void construct_graph() {
    for(int i = 0; i < 2; ++i) {
        book[i].push_back(2000000000); book[i].push_back(2000000001);
        sort(book[i].begin(), book[i].end());
    }
    for(int o = 0; o < 2; ++o) {
        for(int i = 0; i < book[o].size(); ++i) {
            jiou_book[o][book[o][i] % 2].push_back(book[o][i]);
            jiou_book_idx[o][book[o][i] % 2].push_back(i);
        }
        for(int i = 0; i < book[o].size(); ++i) {
            if(i == book[o].size() - 1) {
                father[o][i][0] = i;
                dist[o][i][0] = 0;
            }
            else {
                int jiou = (1 ^ (book[o][i]) % 2);
                int idx = (int)(upper_bound(jiou_book[o][jiou].begin(), jiou_book[o][jiou].end(), book[o][i]) - jiou_book[o][jiou].begin());
                father[o][i][0] = jiou_book_idx[o][jiou][idx];
                dist[o][i][0] = jiou_book[o][jiou][idx] - book[o][i];
            }
        }
        for(int k = 1; k < 20; ++k) {
            for(int i = 0; i < book[o].size(); ++i) {
                int enen_father = father[o][i][k - 1];
                father[o][i][k] = father[o][enen_father][k - 1];
                dist[o][i][k] = dist[o][i][k - 1] + dist[o][enen_father][k - 1];
            }
        }
    }
}

bool check_int(ll x, vector<ll>&book) {
    int idx = (int)(lower_bound(book.begin(), book.end(), x) - book.begin());
    return book[idx] == x;
}

int get_now_dir(vector<ll>&pos, ll now_time) {
    // 当前位置在(x,y), 执行第now_time步, 走哪个方向
    // 0 dong, 1 bei
    int now_dir = -1;
    if(check_int(pos[0], book[0]) && check_int(pos[1], book[1])) {
        now_dir = 1;
    }
    else if(check_int(pos[0], book[0])) {
        now_dir = 1;
    }
    else {
        now_dir = 0;
    }
    if(now_time % 2 == 0) {
        now_dir ^= 1;
    }
    return now_dir;
}
int jiou_of_dir[2] = {0, 1};

void walk_to_guaidian(vector<ll>&pos, ll now_dir, ll &begin_time) {
    // 东->北, 偶数时刻,
    // 北->东, 奇数时刻,
    int jiou_of_guaidian_time = jiou_of_dir[now_dir ^ 1];
    int jiou_of_begin_time = begin_time % 2;
    int jiou_of_now_pos = pos[now_dir] % 2;
    int need_book_jiou = (jiou_of_begin_time ^ jiou_of_guaidian_time ^ jiou_of_now_pos);
    int idx = (int)(upper_bound(jiou_book[now_dir][need_book_jiou].begin(), jiou_book[now_dir][need_book_jiou].end(), pos[now_dir]) - jiou_book[now_dir][need_book_jiou].begin());
    ll temp = min(d, jiou_book[now_dir][need_book_jiou][idx] - pos[now_dir]);
    d -= temp;
    pos[now_dir] += temp;
    begin_time += temp;
}

void little_walk(vector<ll>&pos, ll &begin_time) {
    // （1）在当前方向，一直走到拐点。（2）转弯，一直走到拐点。（3）若行动力不够实现（1）（2）。直接返回。
    //  begin_time第一次行动是第几次。
    int now_dir = get_now_dir(pos, begin_time);
    walk_to_guaidian(pos, now_dir, begin_time);
    now_dir = get_now_dir(pos, begin_time);
    walk_to_guaidian(pos, now_dir, begin_time);
}

void solve(vector<ll>&pos) {
    ll begin_time = 1;
    little_walk(pos, begin_time);
    // 开始倍增迅速循环 拐弯
    if(d == 0) {
        return;
    }
    for(int k = 19; k >= 0; --k) {
        int idx[2];
        for(int j = 0; j < 2; ++j) {
            idx[j] = (int)(lower_bound(book[j].begin(), book[j].end(), pos[j]) - book[j].begin());
            assert(book[j][idx[j]] == pos[j]);
        }
        ll tot_dist = dist[0][idx[0]][k] + dist[1][idx[1]][k];
        if(tot_dist <= d) {
            d -= tot_dist;
            pos[0] += dist[0][idx[0]][k];
            pos[1] += dist[1][idx[1]][k];
            begin_time += tot_dist;
        }
    }
    little_walk(pos, begin_time);
}


int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        int o;
        cin >> s >> o;
        if(s == "V") {
            book[0].push_back(o);
        }
        if(s == "H") {
            book[1].push_back(o);
        }
    }
    construct_graph();
    for(int i = 1; i <= q; ++i) {
        ll x, y;
        cin >> x >> y >> d;
        vector<ll>pos{x, y};
        solve(pos);
        cout << pos[0] << " " << pos[1] << endl;
    }
    return 0;
}