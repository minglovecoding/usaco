#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> check(const vector<int>& Restore) {
    vector<int> c;
    int i = 0, j = Restore.size() - 1;
    while (i < j) {
        if (Restore[i] > Restore[j]) {
            i++;
            c.push_back(Restore[i]);
        } else {
            j--;
            c.push_back(Restore[j]);
        }
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> initList(n-1);
        set<int> initSet;
        for (int i=0;i<n-1 ;++i) {
        	int temp;
            cin >> temp;
            initList[i] = temp;
            initSet.insert(temp);
        }

        int length = initSet.size();
        if (length < n - 2) {
            cout << -1 << endl;
            continue;
        }

        if (length == n - 1) {
            int missingNumber;
            
            for (int i = 1; i <= n; ++i) {
                if (initSet.find(i) == initSet.end()) {
                    missingNumber = i;
                    break;
                }
            }
            vector<int> Restore;
            Restore.push_back(missingNumber);
            Restore.insert(Restore.end(), initList.begin(), initList.end());

            vector< vector<int> > ans;

            vector<int> c = Restore;
            if (check(c) == initList) {
                ans.push_back(Restore);
            }

            reverse(Restore.begin(), Restore.end());
            c = Restore;
            if (check(c) == initList) {
                ans.push_back(Restore);
            }

            if (!ans.empty()) {
                if(ans[0] < ans[1]){
                	for (int i=0;i<ans[0].size()-1;i++) {
                    	cout << ans[0][i] << " ";
                	}
                	cout <<ans[0][ans[0].size()-1] <<endl;
				}else{
					for (int i=0;i<ans[1].size()-1;i++) {
                    	cout << ans[1][i] << " ";
                	}
                	cout <<ans[1][ans[1].size()-1] <<endl;
				}
            } else {
                cout << -1 << endl;
            }
            continue;
        }

        vector<int> rest;
        for (int i = 1; i <= n; ++i) {
            if (initSet.find(i) == initSet.end()) {
                rest.push_back(i);
            }
        }
        int x = rest[0], y = rest[1];

        vector< vector<int> > ans;
        
        vector< vector<int> > testCases;
        vector<int> tempX;
        tempX.push_back(x);
        tempX.push_back(y);
        testCases.push_back(tempX);
        vector<int> tempY;
        tempY.push_back(y);
        tempY.push_back(x);
        testCases.push_back(tempY);
        for (auto& testCase : testCases) {
            vector<int> Restore(n, 0);
            Restore[0] = testCase[0];
            Restore[n-1] = testCase[1];
            int i = 0, j = n - 1, cur = 0;
            while (i < j) {
                if (Restore[i] > Restore[j]) {
                    i++;
                    Restore[i] = initList[cur++];
                } else {
                    j--;
                    Restore[j] = initList[cur++];
                }
            }
            if (check(Restore) == initList) {
                ans.push_back(Restore);
            }
        }

        if (!ans.empty()) {
                if(ans[0] < ans[1]){
                	for (int i=0;i<ans[0].size()-1;i++) {
                    	cout << ans[0][i] << " ";
                	}
                	cout <<ans[0][ans[0].size()-1] <<endl;
				}else{
					for (int i=0;i<ans[1].size()-1;i++) {
                    	cout << ans[1][i] << " ";
                	}
                	cout <<ans[1][ans[1].size()-1] <<endl;
				}
            } else {
                cout << -1 << endl;
            }
    }
    return 0;
}