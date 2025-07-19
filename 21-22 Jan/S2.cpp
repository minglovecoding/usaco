#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
struct node {
	int v;
	int pos;
};
int main() {
	ll ans = 0;
	int n;
	cin >> n;
	stack<node>stk;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (!stk.empty()) {
			do {
				ans += i - stk.top().pos + 1;
				if (x > stk.top().v) {
					stk.pop();
				}
				else {
					break;
				}
				if (stk.empty()) {
					break;
				}
			} while (1);
		}
		stk.push((node) { x, i });
	}
	cout << ans << endl;
	return 0;
}