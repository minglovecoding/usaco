#include <iostream>
using namespace std;
int N;
int mat[1001][1001];
bool flag[1001][1001];
int count=0;
int main()
{
	cin>>N;

	for(int i=0;i<N;i++) {
	int x,y;
	cin>>x;
	cin>>y;
    flag[x][y] = true;
			if (mat[x][y] == 3) {
				count++;
			}
			if (mat[x][y] == 4) {
				count--;
			}
			if (x > 0) {
				mat[x - 1][y] ++;
				if (flag[x - 1][y] && mat[x - 1][y] == 3) {
					count++;
				}
				if (flag[x - 1][y] && mat[x - 1][y] == 4) {
					count--;
				}
			}
			if (x < N) {
				mat[x + 1][y] ++;
				if (flag[x + 1][y] && mat[x + 1][y] == 3) {
					count++;
				}
				if (flag[x + 1][y] && mat[x + 1][y] == 4) {
					count--;
				}
			}
			if (y > 0) {
				mat[x][y - 1] ++;
				if (flag[x][y - 1] && mat[x][y - 1] == 3) {
					count++;
				}
				if (flag[x][y - 1] && mat[x][y - 1] == 4) {
					count--;
				}
			}
			if (y < N) {
				mat[x][y + 1] ++;
				if (flag[x][y + 1] && mat[x][y + 1] == 3) {
					count++;
				}
				if (flag[x][y + 1] && mat[x][y + 1] == 4) {
					count--;
				}
			}
			cout<<count<<endl;
	}
   
	return 0;
}
