
/*
ID: manubha1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int final[99];

bool palindrome(int i){
	for(int j=0;j<i;j++){
		if (final[j]!=final[i-1-j]){
			return false;
		}
	}
	return true;
}

bool convert_base_and_check(int number, int base){	
	double remainder;    
	int i=0;
	while (number !=0){
		remainder=(number%base);
		final[i]=remainder;
		i++;
		number=number/base;
	}
	// check if number is palindrome -
	return palindrome(i);
		
}


bool check_condition(int S){
	// check if a number is palindromic in 2 or more bases.
	int c=0;
	for(int base=2;base<=10;base++){
		if(convert_base_and_check(S,base)){
			c++;
			if(c>=2){
				return true;
			}
		}
	}
	return false;
}

int main(){
		
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int N;
	int S;
	fin >> N >> S;
	bool f;

	while(N>0){
		S++;
		if(check_condition(S)){
			N--;
			fout << S << endl;
		}
	}

}