/*
ID: manubha1
PROG: numtri
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

using namespace std;

typedef vector<int> vec;


int main(){
		
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	


	int N,i,j,k;
	fin >> N;
	vector< vector<int> > s(N);
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			fin >> k;
			s[i].push_back(k);
		}
	}
	// for(i=0;i<N;i++){
	// 	for(j=0;j<s[i].size();j++){
	// 		cout << s[i].at(j) << "  ";
	// 	}
	// 	cout << endl;
	// }

	for(i=N-1;i>0;i--){

		for(j=0;j<i;j++){
			s[i-1][j] = s[i-1][j] + max(s[i][j], s[i][j+1]);
		}
	}
	
	fout << s[0][0] << endl;



}