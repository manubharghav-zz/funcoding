/*
ID: manubha1
PROG: palsquare
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

ifstream fin;
ofstream fout;


bool palindrome(int i){

	for(int j=0;j<i;j++){
		if (final[j]!=final[i-1-j]){
			return false;
		}
	}
	return true;
}

int final1[99];

void convert_base(int number, int base){	
	double remainder;    
	int i=0;
	while (number !=0){
		remainder=(number%base);
		final1[i]=remainder;
		i++;
		number=number/base;
	}
	
	for (i--; i>-1; i--){
		if (final1[i]<10)
			fout<<final1[i];
		else
			fout<<char(final1[i]-10+'A');
	}	
}

void convert_base_and_check(int n, int base){

	int number = n*n;	
	double remainder;    
	int i=0;
	while (number !=0){
		remainder=(number%base);
		final[i]=remainder;
		i++;
		number=number/base;
	}
	// check if number is palindrome -
	if(palindrome(i)){
		convert_base(n,base);
		fout << " " ;
		for (i--; i>-1; i--){
			if (final[i]<10)
				fout<<final[i];
			else
				fout<<char(final[i]-10+'A');
		}
		fout << endl;
	}
		
}





int main(){
		
	fin.open("palsquare.in");
	fout.open("palsquare.out");
	int base;
	fin >> base;
	for(int i=1;i<301;i++){
		convert_base_and_check(i,base);
	}

	fin.close();
	fout.close();
	return 0;
}