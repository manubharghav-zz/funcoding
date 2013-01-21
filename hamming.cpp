/*
ID: manubha1
PROG: hamming
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

bool graph[255][255];
int glimit;
vector<int> v;
int N;

int getHammingDistance(int x, int y){
	int dist=0;
	while(x!=0 || y!=0){
		dist+=(x%2 ^ y%2);
		x=x>>1;
		y=y>>1;
	}
	return dist;
}

// size of the set required.
bool ins(int n){
	for(int i=0;i<v.size();i++){
		if(!graph[v[i]][n]){
			return false;
		}
	}
	return true;
}
int backTrack(int n,int ans){
	ans++;
	int tmp3 = v.back();
	v.pop_back();
	if(v.size()==0){
		if (tmp3==glimit) {
			return  1 - n;
		}
		else{
			v.push_back(++tmp3);
			return (-n+N);
		}
	}
	int tmp = v.back();
	for(int i=tmp+1;i<=glimit;i++){
		if(ins(i) && i!=tmp3){
			v.push_back(i);
			return ans;
		}
	}
	return  backTrack(n,ans);
}
void recurse(int n){
	int n1;
	if(n==0){
		return ;
	}
	else{
		int tmp = v.back();
		if (tmp>= glimit){
			n1 = n + backTrack(n,0) - 1;
		}
		else{
			for(int i=tmp+1;i<=glimit;i++){
				if(ins(i)){
					v.push_back(i);
					n1=n-1;
					break;
				}
			}
			if(n1==n){
				n1 = n + backTrack(n,0) - 1;
			}			
		}
		recurse(n1);
	}
}
int main(){		
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	int  B, D,i,j;
	fin >> N >> B >> D ;
	glimit = pow(2,B) -1;
	for(i=0;i<=glimit;i++){
		for(j=i+1;j<=glimit;j++){
			if(getHammingDistance(i,j) >= D){
				graph[i][j]=true;
				graph[j][i]=true;
			}
			else{
				graph[i][j]=false;
				graph[j][i]=false;
			}
		}
	}
	v.push_back(0);
	recurse(N-1);
	if(v.size() < N){
		return 0;
	}	
	for(i=0;i<v.size();i++){
		fout << v[i] ;
		if((i+1)%10 == 0 || (i==v.size()-1)){
			fout << endl;
		}
		else{
			fout << " ";
		}
	}
}