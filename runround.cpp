
/*
ID: manubha1
PROG: runround
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
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;





bool check(unsigned long  n){
	while (n>0){
		if(n%10==0){return false;}
		n=n/10;
	}
	return true;
}

string ltos(unsigned long n){

	std::stringstream ss ;
	ss<< n;  // or any other type
    std::string r=ss.str();   // use .str() to get a string back
    return r;
}  

bool checkRunRound(unsigned long n){

	set<int> visited;
	string r = ltos(n);
    char buffer[256];
    int l = r.length();//length of string
    int next = 0;
    int start;
    for(int i=0;i<l;i++){
    	char c = r[next];
    	start = atoi(&c);
    	if(visited.size()!=0 && visited.find(start)!=visited.end()){
    		visited.clear();
    		return false;
    	}
    	visited.insert(start);
    	if(r[next]=='0'){
    		visited.clear();
    		return false;
    	}
	   	r[next] = '0';
       	next= (next + (start % l))%l;
    }

    strcpy(buffer,r.c_str());
    unsigned long  final  = atol(buffer);
    if (final==0 && next==0){
    	visited.clear();
    	return true;
    }
    else{
    	visited.clear();
    	return false;
    }

}
int main(){
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	unsigned long s;
	fin >> s;
	while(true){
		s=s+1;
		if (check(s)){
		if (checkRunRound(s)){
			fout << s << endl;
			return 0;
		}
		}
	}
}