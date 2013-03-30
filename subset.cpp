/*
ID: manubha1
PROG: subset
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


int arr[781][40];
int n;



int solution(int sum, int n){
	int i,j,k;
	for(i=0;i<=sum;i++){
		arr[i][0]=0;
	}
	for(i=0;i<=n;i++){
		arr[0][i]=0;
	}
	arr[0][0]=1;

	for(i=1;i<=sum;i++){
		for(j=1;j<=n;j++){

			if((i-j)<0){
				arr[i][j]=arr[i][j-1];
			}
			else{
				arr[i][j]=arr[i-j][j-1] + arr[i][j-1];
			}
		}
	}



	return arr[sum][n];



}




int main(){
		
	ifstream fin("subset.in");
	ofstream fout("subset.out");


	fin >> n;

	int sum = (n*(n+1))/2;
	if(sum%2==1){
		fout << 0 << endl;
	}
	else{
		fout << solution(sum/2,n) << endl;
	}






	


}