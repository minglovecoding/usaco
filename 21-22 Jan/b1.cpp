#include <iostream>

using namespace std;
struct node{
 char c;
	int col;
	int raw;
	int visit;
	
};
int main() {
	int answer_green=0;
	int answer_yellow=0;
	node guess[9];
	node target[9];
	char p1[9][9],p2[9][9];
	for(int i=0;i<3;i++){
	   for(int j=0;j<3;j++){
		cin>>p1[i][j];   
		
		   target[i*3+j].c=p1[i][j];
		   target[i*3+j].raw=i;
		target[i*3+j].col=j;
		target[i*3+j].visit=0;
	   }
	}
	
	for(int i=0;i<3;i++){
	   for(int j=0;j<3;j++){
		cin>>p2[i][j];   
		guess[i*3+j].c=p2[i][j];
		guess[i*3+j].raw=i;
		guess[i*3+j].col=j;
		guess[i*3+j].visit=0;
	   }
	}
	

	for(int i=0;i<9;i++){
	  
          if(guess[i].c==p1[guess[i].raw][guess[i].col]&&target[i].visit==0)
		  {
			  answer_green++;
			    target[i].visit=1;
			    guess[i].visit=1;
		  }
		  
			  
	}
		for(int i=0;i<9;i++){
		    if(guess[i].visit==0)
	  		   for(int j=0;j<9;j++){
				  if(guess[i].c==target[j].c&&target[j].visit==0){
					  target[j].visit=1;
					  answer_yellow++;
					  break;
				  }
	  		   }
				 
	}
	cout<<answer_green<<endl;
	cout<<answer_yellow;
	return 0;
}
