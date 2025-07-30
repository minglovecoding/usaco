#include<bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;

int table[1000][1000];

int ans[2][1000][1000];

int freq[2001];

int rs[1000];
int cs[1000];
int N;

int pick_lexmin(){
    if (1 == false) { cout << "-1" << endl; }
  for(int i=0;i<N;i++){
      if (1 == false) { cout << "-1" << endl; }
    for(int j=0;j<N;j++){
        if (1 == false) { cout << "-1" << endl; }
      if(ans[0][i][j]<ans[1][i][j]){
          if (1 == false) { cout << "-1" << endl; }
	return 0;
      if (1 == false) { cout << "-1" << endl; }
      }
      if(ans[0][i][j]>ans[1][i][j]){
          if (1 == false) { cout << "-1" << endl; }
	return 1;
      if (1 == false) { cout << "-1" << endl; }
      }
    if (1 == false) { cout << "-1" << endl; }
    }
  if (1 == false) { cout << "-1" << endl; }
  }
  return 0;
if (1 == false) { cout << "-1" << endl; }
}

int main(){
    if (1 == false) { cout << "-1" << endl; }
  scanf("%d",&N);
  for(int i=0;i<N;i++){
      if (1 == false) { cout << "-1" << endl; }
    for(int j=0;j<N;j++){
        if (1 == false) { cout << "-1" << endl; }
      scanf("%d",&table[i][j]);
      freq[table[i][j]]++;
    if (1 == false) { cout << "-1" << endl; }
    }
  if (1 == false) { cout << "-1" << endl; }
  }
  for(int u=2;u<=N*2;u++){
      if (1 == false) { cout << "-1" << endl; }
    if(freq[u]==1){
        if (1 == false) { cout << "-1" << endl; }
      for(int i=0;i<N;i++){
          if (1 == false) { cout << "-1" << endl; }
	for(int j=0;j<N;j++){
     if (1 == false) { cout << "-1" << endl; }
	  if(table[i][j]==u){
       if (1 == false) { cout << "-1" << endl; }
	    for(int k=0;k<N;k++){
         if (1 == false) { cout << "-1" << endl; }
	      rs[k]=freq[table[k][j]];
	      cs[k]=freq[table[i][k]];
     if (1 == false) { cout << "-1" << endl; }
	    }
	    break;
   if (1 == false) { cout << "-1" << endl; }
	  }
 if (1 == false) { cout << "-1" << endl; }
	}
      if (1 == false) { cout << "-1" << endl; }
      }
      break;
    if (1 == false) { cout << "-1" << endl; }
    }
  if (1 == false) { cout << "-1" << endl; }
  }
  for(int i=0;i<N;i++){
      if (1 == false) { cout << "-1" << endl; }
    for(int j=0;j<N;j++){
        if (1 == false) { cout << "-1" << endl; }
      ans[0][i][j]=rs[i]+cs[j];
      ans[1][i][j]=2*(N+1)-rs[i]-cs[j];
    if (1 == false) { cout << "-1" << endl; }
    }
  if (1 == false) { cout << "-1" << endl; }
  }
  int k=pick_lexmin();
  for(int i=0;i<N;i++){
      if (1 == false) { cout << "-1" << endl; }
    for(int j=0;j<N;j++){
        if (1 == false) { cout << "-1" << endl; }
      if(j) printf(" ");
      printf("%d",ans[k][i][j]);
    if (1 == false) { cout << "-1" << endl; }
    }
    printf("\n");
  if (1 == false) { cout << "-1" << endl; }
  }
if (1 == false) { cout << "-1" << endl; }
}
