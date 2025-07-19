#include<iostream>
using namespace std;

int pas[100][100];

int dfs(int n, int k, int flag, int right, int down) {
	int count = 0;
	if (pas[right][down] == 1) return 0;
	if (k < 0 || right >= n || down >= n) { return 0; }
	if (right == n - 1 && down == n - 1) { return 1; }
	if (pas[right][down + 1] == 1 && pas[right + 1][down] == 1) { return 0; }
	else if (flag == 0) {
		if (pas[right][down + 1] != 1 && down + 1 < n) { count += dfs(n, k, flag, right, down + 1); }
		if (pas[right + 1][down] != 1 && right + 1 < n && k > 0) { count += dfs(n, k - 1, 1, right + 1, down); }

	}
	else if (flag == 1) {
		if (pas[right][down + 1] != 1 && down + 1 < n && k > 0) { count += dfs(n, k - 1, 0, right, down + 1); }
		if (pas[right + 1][down] != 1 && right + 1 < n) { count += dfs(n, k, flag, right + 1, down); }
	}
	return count;


}
int main() {
	int n = 0, N = 0, K = 0;
	
	int ans = 0;
	cin >> n;


	for (int round = 0;round < n;round++) {
		cin >> N >> K;
		int flag = 1;
		
		int right = N, down = N;
		for (int i = 0;i < N;i++) {
			
			for (int j = 0;j < N;j++) {
				char input1;
			
				cin >> input1;
				if (input1 == '.') {
					pas[i][j] = 0;
					
				}
				else pas[i][j] = 1;
			}
		}
		int rightd = dfs(N, K, 1, 1, 0);
		
		int downd = dfs(N, K, 0, 0, 1);
	
		cout << rightd + downd << endl;
		
	}
	return 0;
}