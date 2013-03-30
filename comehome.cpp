/*
ID: manubha1
PROG: comehome
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
	
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	
	int dist[58][58];
	
	fill(&dist[0][0], &dist[57][57],20000000);

	int tmp;
	fin >> tmp;
	char src,dest;
	for(int i=0;i<tmp;i++){
		fin >> src >> dest;
		int tmp;
		fin >> tmp;
		if(tmp < dist[(int)(src-'A')][(int)(dest-'A')]){
			dist[(int)(src-'A')][(int)(dest-'A')]=tmp;
			dist[(int)(dest-'A')][(int)(src-'A')] = dist[(int)(src-'A')][(int)(dest-'A')];

		}
		dist[(int)(dest-'A')][(int)(src-'A')] = dist[(int)(src-'A')][(int)(dest-'A')];
		// cout << (src-'A') << "  " <<dest-'A' << endl;
	}
	for(int k=0;k<58;k++){
		for(int i=0;i<58;i++){
			for(int j=0;j<58;j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					dist[j][i] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	char c;
	int ans=20000000;

	// cout << 'Z'-'A' << endl;
	for(int i=0;i<25;i++){
		if(ans>dist['Z'-'A'][i]){
			ans = dist['Z'-'A'][i];
			c = (char)'A'+i ;
		}
		
	}
	for(int i=0;i<25;i++){
		if(ans>dist[i]['Z'-'A']){
			ans = dist[i]['Z'-'A'];
			c = (char)'A'+i ;
		}
		
	}

	// cout<< dist[(int)('Z'-'A')][(int)('A'-'A')] << endl;

	fout << c << " " << ans <<endl;




}