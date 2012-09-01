/*
ID: manubha1
PROG: packrec 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;



class rec{
public:
	int len;
	int bre;
	rec(int x,int y):len(x),bre(y){

	}


};


int main(){
		
	ifstream fin("packrec.in");
	ofstream fout("packrec.out");

	vector<rec> v;
	int x,y;
	for(int i=0;i<4;i++){
		fin >> x >>y ;
		v.push_back(max(x,y),min(x,y));
	}


	int area = 10000;

	vector<rec> ans;

	ans.push_back

	


}