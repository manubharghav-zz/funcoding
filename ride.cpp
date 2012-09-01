/*
ID: manubha1
PROG: ride
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	ifstream fid("ride.in");
	ofstream fout("ride.out");
	string a,b;
	fid >> a >> b;
	int a1=1,b1=1;
	for(int i=0;i<a.length();i++){
		a1 = a1 * ((int)a[i]-64);
	}
	for(int i=0;i<b.length();i++){
		b1 = b1 * ((int)b[i]-64);
	}
	if (a1%47==b1%47){
		fout <<"GO" <<endl;
	}
	else{
		fout <<"STAY"<< endl;
	}
}