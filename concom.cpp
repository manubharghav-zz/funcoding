/*
ID: manubha1
PROG: concom
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
int main(){
		
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	int n;

	fin >> n;

	int control[101][101];
	bool controls[101][101];
	int cont[101][101];


	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			controls[i][j]=false;
			control[i][j]=0;
		}
	}

	typedef std::pair< int, int > TCompanyCtrol;
	typedef std::set< TCompanyCtrol > TCmpCtrlSet;


	int i, j, p;
	TCmpCtrlSet Solset;

	while(fin >> i >>j >>p){
		control[i-1][j-1] = p;
		cont[i-1][j-1] = p;
	}
	n=101;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && cont[i][j]>50 &&!controls[i][j]){
				Solset.insert( TCompanyCtrol( i, j ) );

				// add k's stock to i.
				for ( int w=0; w<n; w++	)
				{
					cont[i][w] += control[j][w];
				}

				controls[i][j] = true;
				// recheck i.
				j = -1;
			}
		}
	}

	// cout << Solset.size() << endl;
	for ( TCmpCtrlSet::iterator iter = Solset.begin(); iter != Solset.end(); ++iter )
	{
		fout << iter->first + 1 << " " << iter->second + 1 << endl;
	}

	fin.close();
	fout.close();








	


}