#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Section {
    long long begin;
    long long haybales;
    Section(long long begin, long long haybales) {
        this->begin = begin;
        this->haybales = haybales;
    }
};

struct Comparator {
    bool operator()(Section& s1, Section& s2) {
        return s1.begin > s2.begin;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long T;
    cin >> N >> T;

    priority_queue<Section, vector<Section>, Comparator> pq;
    priority_queue<Section, vector<Section>, Comparator> pq2;

    for (int i = 0; i < N; i++) {
        long long d, b;
        cin >> d >> b;
        pq.push(Section(d, b));
    }

    while (pq.size() > 1) {
        Section s1 = pq.top();
        pq.pop();
        Section s2 = pq.top();
        pq.pop();

        if (s1.begin + s1.haybales - 1 >= s2.begin) {
            s1.haybales += s2.haybales;
            pq.push(s1);
        }
        else {
            pq2.push(s1);
            pq.push(s2);
        }
    }

    pq2.push(pq.top());
    long long ans = 0;

    while (!pq2.empty()) {
        Section s = pq2.top();
        pq2.pop();

        if (s.begin <= T && s.haybales >= T) {
            ans += T - s.begin + 1;
        }
        if (T > s.haybales) {
            ans += s.haybales;
        }
    }

    cout << ans << endl;

    return 0;
}
