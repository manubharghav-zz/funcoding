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

#ifdef _WIN32
#define THINKINGL 1
#endif



int main()
{
	string strProblemName = "concom";

	string strInFile = strProblemName + ".in";
	string strOutFile = strProblemName + ".out";


	ofstream fout ( strOutFile.c_str() );
	ifstream fin ( strInFile.c_str() );

	if( !fin )
	{
		cout << "open input file fail!" << endl;
		return 0;
	}

	const int MAX_COMPANY_NUM = 100+1;
	int g_arCompanyStockOr[MAX_COMPANY_NUM][MAX_COMPANY_NUM];
	memset( g_arCompanyStockOr, 0, sizeof( g_arCompanyStockOr ) );

	int nCompanyNum;
	fin >> nCompanyNum;
	int nOwnerIndex, nOwnedIndex, nShare;
	while( fin >> nOwnerIndex >> nOwnedIndex >> nShare )
	{
		g_arCompanyStockOr[ nOwnerIndex - 1 ][ nOwnedIndex - 1 ] += nShare;
	}

	int g_arCompanyStock[MAX_COMPANY_NUM][MAX_COMPANY_NUM];
	memcpy( g_arCompanyStock, g_arCompanyStockOr, sizeof( g_arCompanyStockOr ) );

	typedef std::pair< int, int > TCompanyCtrol;
	typedef std::set< TCompanyCtrol > TCmpCtrlSet;

	bool arIsChecked[MAX_COMPANY_NUM][MAX_COMPANY_NUM];
	memset( arIsChecked, 0, sizeof( arIsChecked ) );

	TCmpCtrlSet tRetSet;

	nCompanyNum = MAX_COMPANY_NUM;

	for ( int i=0; i<nCompanyNum; ++i )
	{
		for ( int k=0; k<nCompanyNum; ++k )
		{
			if ( i != k && g_arCompanyStock[ i ][ k ] > 50 && !arIsChecked[i][k] )
			{
				// i control k.
				tRetSet.insert( TCompanyCtrol( i, k ) );

				// add k's stock to i.
				for ( int w=0; w<nCompanyNum; ++w )
				{
					g_arCompanyStock[ i ][w] += g_arCompanyStockOr[ k ][ w ];
				}

				arIsChecked[i][k] = true;
				// recheck i.
				k = -1;
			}
		}
	}

	for ( TCmpCtrlSet::iterator iter = tRetSet.begin(); iter != tRetSet.end(); ++iter )
	{
		fout << iter->first + 1 << " " << iter->second + 1 << endl;
	}

	fin.close();
	fout.close();
	//	delete[] g_arDPUnitAmount;

#ifdef THINKINGL

	cout << "use clock: " << clock() << " / " << CLOCKS_PER_SEC << endl;

	cout << "-----------begin--dump--output--file----------------" << endl << endl;
	system( ( string( "type " ) + strOutFile ).c_str() );

	cout << endl;

	system( "pause" );
#endif

	return 0;
}