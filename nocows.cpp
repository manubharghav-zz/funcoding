/*
ID: manubha1
PROG: nocows
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
#define MOD 9901
using namespace std;
 
int table[101][202],N,K,c;
int smalltrees[101][202];
 
FILE *fin=fopen("nocows.in","r");
FILE *fout=fopen("nocows.out","w");
 
int main() {
    fscanf (fin,"%d %d",&N,&K);
    table[1][1]=1;
    for (int i=2;i<=K;i++) {
        for (int j=1;j<=N;j+=2)
            for (int k=1;k<=j-1-k;k+=2) {
                if (k!=j-1-k) c=2; else c=1;
                table[i][j]+=c*(
                        smalltrees[i-2][k]*table[i-1][j-1-k]  // left subtree smaller than i-1
                        +table[i-1][k]*smalltrees[i-2][j-1-k]  // right smaller
                        +table[i-1][k]*table[i-1][j-1-k]);// both i-1
                table[i][j]%=MOD;
            }
        for (int k=0;k<=N;k++) {          // we ensure that smalltrees[i-2][j] in the next i
            smalltrees[i-1][k]+=table[i-1][k]+smalltrees[i-2][k]; // iteration contains the number
            smalltrees[i-1][k]%=MOD;           // of trees smaller than i-1 and with j nodes
        }
    }
 
    fprintf (fout,"%d\n",table[K][N]);
    return 0;
}