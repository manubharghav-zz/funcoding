/*
ID: manubha1
PROG: preface
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


char nums[]={'I','V','X','L','C','D','M'};
int allcount[10];


void getromannum(int a){
    if (a<4) allcount[0]+=a;
    else if (a==4) {allcount[0]++; allcount[1]++;}
    else if (a<9) {allcount[1]++; getromannum(a-5);}
    else if (a==9) {allcount[0]++; allcount[2]++;}
    else if (a<40) {allcount[2]++; getromannum(a-10);}
    else if (a<50) {allcount[2]++; allcount[3]++; getromannum(a-40);}
    else if (a<90) {allcount[3]++; getromannum(a-50);}
    else if (a<100) {allcount[2]++; allcount[4]++; getromannum(a-90);}
    else if (a<400) {allcount[4]++; getromannum(a-100);}
    else if (a<500) {allcount[4]++; allcount[5]++; getromannum(a-400);}
    else if (a<900) {allcount[5]++; getromannum(a-500);}
    else if (a<1000) {allcount[4]++; allcount[6]++; getromannum(a-900);}
    else {allcount[6]++; getromannum(a-1000);}
}

int main(){
   
    ifstream fin("preface.in");
	ofstream fout("preface.out");
    int n,i;
    fin >> n;
    for (i=0;i<=6;i++) {allcount[i]=0;}
    for (i=1;i<=n;i++) {getromannum(i);}
    for (i=0;i<=6;i++) {
    	if (allcount[i]!=0) 
    		{fout << nums[i] << " " <<allcount[i] << endl;}
    }
    return 0;
}