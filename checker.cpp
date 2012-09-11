/*
ID: manubha1
PROG: checker
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;

int board[13][13];
int columns[13];
int sizeOfBoard;
int noOfSolutions=0;
int printTime = 3;
int acol[13];
ofstream fout;



bool collide(int x1,int y1, int x2,int y2){
	if (abs(x2 - x1) == abs(y2 - y1)){
		return true;
	}
	return false;
}

void place(int x, int y){
	int p,q;
	p=x+1;
	q=y+1;
	while(p<sizeOfBoard && q<sizeOfBoard){
		board[p][q] = board[p][q] + 1;
		p=p+1;
		q=q+1;
	}
	p=x-1;
	q=y-1;
	while(p>=0 && q >=0){
		board[p][q] = board[p][q] + 1;
		p--;
		q--;
	}
	p=x-1;
	q=y+1;
	while(p>=0 && q<sizeOfBoard){
		board[p][q] = board[p][q] + 1;
		p--;
		q++;
	}

	p=x+1;
	q=y-1;
	while(p<sizeOfBoard && q>=0){
		board[p][q] = board[p][q] + 1;
		p++;
		q--;
	}

}

void unplace(int x, int y){
	int p,q;
	p=x+1;
	q=y+1;
	while(p<sizeOfBoard && q<sizeOfBoard){
		board[p][q] = board[p][q] -1;
		p=p+1;
		q=q+1;
	}
	p=x-1;
	q=y-1;
	while(p>=0 && q >=0){
		board[p][q] = board[p][q] -1;
		p--;
		q--;
	}
	p=x-1;
	q=y+1;
	while(p>=0 && q<sizeOfBoard){
		board[p][q] = board[p][q] -1;
		p--;
		q++;
	}

	p=x+1;
	q=y-1;
	while(p<sizeOfBoard && q>=0){
		board[p][q] = board[p][q] -1;
		p++;
		q--;
	}

}

bool check(int x, int j){
	for(int i=0;i<x;i++){
		if(collide(i,columns[i],x,j)){
			return false;
		}
	}

	return true;
}

void printSolution(){
	for(int i=0;i<sizeOfBoard-1;i++){
		fout << columns[i]+1 << " ";
	}

	fout << columns[sizeOfBoard-1]+1 <<endl;
}


void solve(int x){
	if(x == sizeOfBoard){
		if(printTime > 0){
			printSolution();
			printTime--;
		}
		noOfSolutions++;
	}

	else{
		
		for(int y=0;y<sizeOfBoard;y++){
			if(acol[y]==0){
				if(board[x][y]==0){
					acol[y]=1;
					place(x,y);
					columns[x] = y;
					solve(x+1);
					acol[y]=0; 
					unplace(x,y);
				}
			}
		}

	}
}




int main(){
		
	ifstream fin("checker.in");
	fout.open("checker.out");
	
	fin >> sizeOfBoard;

	for(int i=0;i<sizeOfBoard;i++){
		columns[i]=0;
		acol[i]=0;
		for (int j = 0; j < sizeOfBoard; j++)
		{
			board[i][j]=0;
		}
	}
	solve(0);
	fout << noOfSolutions << endl;
	return 0;
}
