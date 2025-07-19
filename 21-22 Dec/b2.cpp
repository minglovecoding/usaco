#include<iostream>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	int* prefs = new int[num];
	int* temps = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> prefs[i];
	}
	for (int i = 0; i < num; i++)
	{
		cin >> temps[i];
	}
	for (int i = 0; i < num; i++)
	{
		prefs[i] = prefs[i] - temps[i];
	}
	temps[0] =abs(prefs[0]);
	for (int i = 1; i < num; i++) {
		int current_pref = prefs[i];
		int last_pref = prefs[i - 1];
		int pre_mod = temps[i - 1];
		if (current_pref * last_pref > 0) {
			if (current_pref * current_pref <= last_pref * last_pref)
				temps[i] = pre_mod;
			else {
				temps[i] = pre_mod + abs(last_pref - current_pref);
			}
		}
		else {
			temps[i] = pre_mod + abs(current_pref);
		}
	}
	cout << temps[num - 1];

	return 0;
}