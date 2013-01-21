/*
ID: manubha1
PROG: frac1
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

class tuple{
public:
	int a;
	int b;
	tuple(int a1,int b1):a(a1),b(b1){}
};
vector<tuple> ans;
bool value_comparer(tuple i1, tuple i2)
{
if ((i1.a) * (i2.b) < (i2.a)*(i1.b)){
	return true;
}
else if((i1.a) * (i2.b) == (i2.a)*(i1.b)){
	if(i1.a < i2.a){
		return true;
	}
	else if(i1.a == i2.a ){
		return i1.b < i2.b;
	}
	return false;
}
return false;
}


bool equal(tuple i1, tuple i2){
	if ((i1.a) * (i2.b) == (i2.a)*(i1.b)){
	return true;
	}
	return false;
}

int main(){
		
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int n;
	fin >> n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			ans.push_back(tuple(j,i));
		}
	}

	sort(ans.begin(),ans.end(),value_comparer);
	tuple prev = ans[0];
	fout << ans[0].a << "/"<< ans[0].b << endl;
	for(int i=1;i< ans.size();i++){
		if(!equal(ans[i],prev)){
		fout << ans[i].a << "/"<< ans[i].b << endl;
		prev = ans[i];
	}
	}


}