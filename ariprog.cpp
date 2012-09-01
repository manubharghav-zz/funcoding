/*
ID: manubha1
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


int max_size = 250*250 *2 +1;
int p[250*250 *2 +1];
int size_of_p;
ofstream fout;

int nos;
int max1;


class pair1{
public:
	int x,diff;
	pair1(int x1,int diff1):x(x1),diff(diff1){};
};

vector<pair1> v;

void populate(int M){
	for(int i=0;i<=M;i++){
		for(int j=i;j<=M;j++){
			p[i*i + j*j] = 1;
		}
	}	
}

bool myfunction(pair1 i,pair1 j) {
	if(i.diff<j.diff){
		return true;
	}
	else if(i.diff == j.diff){
		return i.x < j.x ;
	}
	else{
		return false;
	}
}

void solve (int N){
	bool found = false;
	for(int i=0;i<=max1 ; i++){
		if(p[i]){
			for(int j=i+1;(j<=max1) && ((i+((j-i)*(N-1)))<= max1);j++){
				if(p[j]){
					// start checking for the complete series
					int diff = j-i;
					bool hit = true;
					for(int l=1;l<=N-1;l++){
						if(!p[i+(diff*l)]){
							hit = false;
						}
					}
					if(hit){
						v.push_back(pair1(i,diff));
					}
				}
			}
		}
	}
}


int main(){

	for(int i=0;i<max_size;i++){
		p[i]=0;
	}
		
	ifstream fin("ariprog.in");
	fout.open("ariprog.out");
	int M,N;
	fin >> N >> M;
	populate(M);
	// mcd = maximum commom difference
	max1 = (M*M) + (M*M);
	solve(N);
	sort(v.begin(),v.end(),myfunction);
	if(v.size()>0){
		for(int i=0;i<v.size();i++){
			fout << v[i].x << " " << v[i].diff << endl;
		}
	}
	else{
		fout << "NONE" << endl;
	}
	

	
}