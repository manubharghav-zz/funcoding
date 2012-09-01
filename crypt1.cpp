/*
ID: manubha1
PROG: crypt1
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



int inset(int a,int set[]){
    int i;
    for (i=0;set[i]!=-1;i++)
        if (a==set[i]) return 1;
    return 0;
}

int numinset(int num,int set[]){
    int i=num;
    for ( ;inset(i%10,set); )
        i/=10;
    return !i;
}

int main(){
    ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
    int n,i,set[9],total=0,k[5],a,b,c,d,e;
    fin >> n;
    for (i=0;i<n;i++) fin >> set[i];
    set[n]=-1;
    
    for (k[0]=0;k[0]<n;k[0]++)
        for (k[1]=0;k[1]<n;k[1]++)
            for (k[2]=0;k[2]<n;k[2]++)
                for (k[3]=0;k[3]<n;k[3]++)
                    for (k[4]=0;k[4]<n;k[4]++){
                        a=100*set[k[0]]+10*set[k[1]]+set[k[2]];
                        b=10*set[k[3]]+set[k[4]];
                        c=a*set[k[3]];
                        d=a*set[k[4]];
                        e=a*b;
                        if ((numinset(c,set))&&(numinset(d,set))&&(numinset(e,set))
                             &&(c<1000)&&(d<1000)&&(e>=1000)&&(e<10000))
                             total++;
                        }
    fout << total << endl;
    return 0;
}



