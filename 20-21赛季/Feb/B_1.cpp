#include <iostream>
#include"string"
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;

int main()
{

	map<string, int> map1;
	map1["Ox"]= 0;
	map1["Tiger"]= 1;
	map1["Rabbit"]= 2;
	map1["Dragon"]= 3;
	map1["Snake"]= 4;
	map1["Horse"]= 5;
	map1["Goat"]= 6;
	map1["Monkey"]=7;
	map1["Rooster"]= 8;
	map1["Dog"]=9;
	map1["Pig"]= 10;
	map1["Rat"]= 11;
	
	
	map<string, int> diff;
	map<string, int> years;

	diff["Bessie"]= 0; 
	years["Bessie"]= 0;
	int N;
	string temp;
	getline(cin, temp);
	N = atoi(temp.c_str());
	int res = 0;
	for (int i = 0; i < N; i++) {


		getline(cin, temp);

		string words[8];
		int a = 0;
		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == ' ')a++;
			else words[a] += temp[j];
		}
			string cow = words[0];
			string flag = words[3];
			string animal = words[4];
			string second_cow = words[7];

		
				years[cow]= map1[animal];
			
			if (flag == "previous") {
				if (years[second_cow] > years[cow]) {
					diff[cow]= diff[second_cow] - (years[second_cow] - years[cow]);
				}
				else {
					diff[cow]=diff[second_cow] - (12 - years[cow] + years[second_cow]);

				}
			}
			else {
				if (years[second_cow] < years[cow]) {

					diff[cow]= diff[second_cow] + (years[cow] - years[second_cow]);

				}
				else {

					diff[cow]= diff[second_cow] + (12 - years[second_cow] + years[cow]);
				}
			}
			
		}

				res = abs(diff["Elsie"]);
				cout << res;
			
		
	return 0;
}
