/*
ID: manubha1
PROG: holstein
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

int flag=0;
int v,g,vlist[30],glist[20][30];
ifstream fin;
ofstream fout;

int find(int gall,int gnow,int chlist[],int alladd[]){
    int i,j;
    if (gall==gnow){

        int flagout=0;
        for (i=0;i<v;i++){
        	if (alladd[i]<vlist[i]) flagout=1;
        } 
        if (flagout==0){
            flag=1;
            fout << gall ;
            for (i=0;i<gall;i++){
            	fout << " " << (chlist[i]+1);
            }
            fout << endl;
            }
        }
    else{
     for (i=(gnow==0)?0:chlist[gnow-1]+1;flag==0 && i<=g-(gall-gnow);i++){
             for (j=0;j<v;j++){ alladd[j]+=glist[i][j];}
             chlist[gnow]=i;
             find(gall,gnow+1,chlist,alladd);
             for (j=0;j<v;j++) {alladd[j]-=glist[i][j];}
             }
     }
}
    


int main(){

	fin.open("holstein.in");
    fout.open("holstein.out");
    int i,j,chosenlist[30],alladdition[30];
    //readfile
    fin >> v;
    for (i=0;i<v;i++){
        fin >> vlist[i];
        alladdition[i]=0;
        }
    fin >>g;
    for (i=0;i<g;i++){
        for (j=0;j<v;j++){
            fin >> glist[i][j];
		}
	}
    //find
    for (i=1;i<=g && flag==0;i++){
        find(i,0,chosenlist,alladdition);
    }
    return 0;
	


}