/*
ID: manubha1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool is_leap(int year){
	if (year%100 == 0){
		if(year%400 == 0){
			return true;
		}
		else{
			return false;
		}
	}
	else if(year%4 ==0 ){
		return true;
	}
	else{
		return false;
	}
}

int mod(int x){
	if (x>=0){return x%7;}
	else{
		return (x+7)%7;
	}
}

int main(){
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int N;
	fin >> N;
	int normal[12]={6,2,2,5,0,3,5,1,4,6,2,4};
	int leap[12] = {6,2,3,6,1,4,6,2,5,0,3,5};
	int hist[7];
	for(int i=0;i<7;i++){
		hist[i]=0;
	}
	int day1 = 1;
	for(int i=1900;i<N+1900;i++){
		if(is_leap(i)){
			for(int j=0;j<12;j++){
				hist[mod(day1+leap[j]-1)] = hist[mod(day1+leap[j]-1)] +1;
			}
		}
		else{
			for(int j=0;j<12;j++){
				hist[mod(day1+normal[j]-1)] = hist[mod(day1+normal[j]-1)] +1;
			}
		}
		//update day1;
		if(is_leap(i)){
			day1 = (day1 + 2)%7;
		}
		else{
			day1 = (day1 + 1)%7;
		}
	}
	fout << hist[6] <<" "<< hist[0] <<" "<< hist[1] <<" "<< hist[2] <<" "<< hist[3] <<" "<< hist[4] <<" "<< hist[5] << endl;
	return 0;
}