/*
ID: manubha1
PROG: maze1
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
#include <cstdio>
#include <cstring>
#include <queue>

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

struct loc { int y, x; loc(int _y, int _x){y=_y;x=_x;} };
int w, h, U[128][128], L[128][128], D[128][128];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

int main()
{
	char s[1024];

	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);

	gets(s);
	sscanf(s, "%d %d", &w, &h);

	memset(U, 0, sizeof(U));
	memset(L, 0, sizeof(L));
	memset(D, 0, sizeof(D));

	for (int r = 1; ; r++) {
		gets(s);
		for (int c = 1; c <= w; c++)
			if (s[2*c-1]==' ') U[r][c]=1;

		if (r > h) break;

		gets(s);
		for (int c = 1; c <= w+1; c++)
			if (s[2*c-2]==' ') L[r][c]=1;
	}


	for (int r=1; r<=h; r++) for (int c=1; c<=w; c++) D[r][c] = INF;

	queue<loc> q;

	for (int i = 1; i <= h; i++) {
		q.push(loc(i,0));
		q.push(loc(i,w+1));
	}

	for (int i = 1; i <= w; i++) {
		q.push(loc(0,i));
		q.push(loc(h+1,i));
	}

	for (; !q.empty(); q.pop()) {
		int y=q.front().y, x=q.front().x;

		if (U[y][x] && D[y-1][x]==INF) {
			D[y-1][x] = D[y][x] + 1;
			q.push(loc(y-1,x));
		}

		if (L[y][x] && D[y][x-1]==INF) {
			D[y][x-1] = D[y][x] + 1;
			q.push(loc(y,x-1));
		}

		if (U[y+1][x] && D[y+1][x]==INF) {
			D[y+1][x] = D[y][x] + 1;
			q.push(loc(y+1,x));
		}

		if (L[y][x+1] && D[y][x+1]==INF) {
			D[y][x+1] = D[y][x] + 1;
			q.push(loc(y,x+1));
		}
	}

	int r = 0;
	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
			if (D[y][x] < INF) r = max(r, D[y][x]);
	printf("%d\n", r);

	return 0;
}