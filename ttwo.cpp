/*
ID: manubha1
PROG: ttwo
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

char c[12][12];

int pos[2][3]={{0}};
int di[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(){
		
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	memset(c,'*',sizeof c);
	char tmp;
	int d = -1;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			fin >> tmp;			
			if(tmp=='C' || tmp=='F'){
				pos[++d][0]=i;
				pos[d][1]=j;
				c[i][j]='.';
			}
			else{
				c[i][j]=tmp;
			}
		}
	}
	for(int i=1;i<=400;i++){

		for(int j=0;j<=1;j++){
			if(c[pos[j][0] + di[pos[j][2]][0]][pos[j][1] + di[pos[j][2]][1]]!='*'){
				pos[j][0] += di[pos[j][2]][0], pos[j][1] += di[pos[j][2]][1];
			}
			else{
                pos[j][2] = (pos[j][2]+1)%4;
			}
		}
		if(pos[0][0]==pos[1][0] && pos[0][1]==pos[1][1]){
			fout << i << endl;
			return 0;
		}

		

	}

	fout << 0 << endl;

	

}