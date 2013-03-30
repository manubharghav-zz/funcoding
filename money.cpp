/*
ID: manubha1
PROG: money
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


int main(){

	ifstream fin("money.in");
	ofstream fout("money.out");

	long long arr[10000][26];
	long long change[26];
	int N,V;
	fin >> V >> N;

	for(int i=0;i<=N;i++){
		for(int j=0;j<=V;j++){
			arr[i][j]=(long long)0;
		}
	}
	change[0]=0;
	for(int i=1;i<=V;i++){
		fin >> change[i];
	}

	sort(&(change[0]),&(change[V+1]));
	// for(int i=0;i<=V;i++){
	// 	cout << change[i] << "  " << endl;
	// }
	//initialization
	for(int i=0;i<=N;i++){
		arr[i][0]=(long long)0;
	}

	for(int i=0;i<=V;i++){
		arr[0][i]=(long long)1;
	}

	
	// cout << arr[0][25] << endl;

	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=V;j++){
			if(i>=change[j]){
				arr[i][j] = arr[i-change[j]][j]+ arr[i][j-1];
			}
			else{
				arr[i][j] = arr[i][j-1];
			}
		}
	}

	// cout << arr[0][25] << endl;
	// for(int i=50;i<=100;i++){

	// 	cout << i << "           " ;
	// 	for(int j=0;j<=25;j++){
	// 		cout << arr[i][j]  << "  " ;
	// 	}
	// 	cout << endl;
	// }

	fout << arr[N][V] << endl;

}
