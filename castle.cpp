/*
ID: manubha1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;

int m,n;

int rooms[50][50];
int input[50][50];
map<int,int> area;
int color_count=0;
typedef std::map<int, int> M;


bool value_comparer(M::value_type &i1, M::value_type &i2)
{
return i1.second<i2.second;
}


void color(int i,int j, int col){

	rooms[i][j] = col;
	area[col] = area[col]+1;
	int s = input[i][j];
	
	if (s%2==0 && rooms[i][j-1]==-2){
		color(i,j-1,col);
	}
	s = s/2;

	if (s%2==0 && rooms[i-1][j]==-2){
		color(i-1,j,col);
	}
	s = s/2;
	if (s%2==0 && rooms[i][j+1]==-2){
		color(i,j+1,col);
	}
	s = s/2;
	if (s%2==0 && rooms[i+1][j]==-2){
		color(i+1,j,col);
	}	
}

int main(){
		
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rooms[i][j]=-2;
			input[i][j] = 0;
			fin >> input[i][j];
		}
	}
	

	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			
			if(rooms[i][j]==-2){
				color_count++;
				color(i,j,color_count);
			}
		}
	}

	fout << area.size() << endl;
	M::iterator itor = std::max_element(area.begin(), area.end(),value_comparer);
	fout << (itor->second) << endl;
	int max_area = 0;
	int wall_r;
	int wall_c;
	char dir;
	for(int i=0;i<n ;i++){
		for(int j=m-1;j>=0;j--){
	
			if(i>=0 && i<n && j>=1 && j<=m && (rooms[j][i]!= rooms[j-1][i]) && area[rooms[j][i]]+area[rooms[j-1][i]]>max_area){
				
				max_area = area[rooms[j][i]]+area[rooms[j-1][i]];
				wall_r = j+1;
				wall_c = i+1;
				dir = 'N';
			}
			if(i>=0 && i+1<n && j>=0 && j<=m && (rooms[j][i]!= rooms[j][i+1]) && area[rooms[j][i+1]]+area[rooms[j][i]]>max_area){
				//cout << i << "  " << j << endl;
				max_area = area[rooms[j][i+1]]+area[rooms[j][i]];
				wall_r = j+1;
				wall_c = i+1;
				dir = 'E';
			}


		}
	}

	fout << max_area << endl;
	fout << wall_r << " " << wall_c << " " << dir << endl;


	// for (int i = 0; i < m; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << rooms[i][j] << "  ";
	// 	}
	// 	cout << endl;
	// }




}