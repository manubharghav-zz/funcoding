/*
ID: manubha1
PROG: fracdec
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <set>
#include <sstream>
#include <algorithm>

#include <memory.h>

#ifdef _WIN32
#include <time.h>
#endif

using namespace std;

#ifdef _WIN32
typedef __int64 n64;
typedef unsigned __int64 u64;
#else
typedef long long n64;
typedef unsigned long long u64;
#endif

#if !defined( _WIN32 )
#define _itoa itoa

char * itoa( int _Val, char * _DstBuf, int _Radix)
{
	sprintf( _DstBuf, "%d", _Val );
	return _DstBuf;
}

#endif

#define INF 0x3FFFFFFF

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


string ans(int N,int D){


	int quotient = N/D; 
	int rem = N%D;
	string decimal;
	if(rem == 0){
		decimal = "0";
	}
	map<int,int> seen;
	int i=0;
	while(rem!=0){
		if(seen.find(rem)==seen.end()){
			seen[rem] = i;
			rem = rem*10;
			if(seen.find(rem)!=seen.end()){
				decimal+="0";
				break;
			}
			while(rem < D){
				decimal+="0";
				rem = rem*10;
				i++;
			}
			decimal+=convertInt(rem/D);
			rem = rem%D;
			i++;
		}
		else{
			break;
		}
	}
	string ans;
	if (rem==0){
		ans = convertInt(quotient) +"." + decimal ;

	}
	else{
		int start_pos = seen[rem];
		decimal.insert(start_pos,"(");
		decimal = decimal +")";
		ans = convertInt(quotient) +"." + decimal;
	}
	return ans;
}










int main(){
		
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");
	int N,D;
	fin >> N >> D;
	string ans1 = ans(N,D);
	int i=0;
	for(int j=0;j<ans1.length();j++){
		if(i==75){
			fout << ans1[j]<<endl;
			i=0;
		}
		else{
			fout << ans1[j];
			i++;
		}
	}
	fout << endl;



}