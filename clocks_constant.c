/*
ID: manubha1
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

int table[9][9]={ {3,3,3,3,3,2,3,2,0},
                  {2,3,2,3,2,3,1,0,1},
                  {3,3,3,2,3,3,0,2,3},
                  {2,3,1,3,2,0,2,3,1},
                  {2,3,2,3,1,3,2,3,2},
                  {1,3,2,0,2,3,1,3,2},
                  {3,2,0,3,3,2,3,3,3},
                  {1,0,1,3,2,3,2,3,2},
                  {0,2,3,2,3,3,3,3,3} };
                
int main(){
   
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");
    int i,k,p,opneed[9],informat[9];
    for (i=0;i<9;i++) opneed[i]=0;
    for (i=0;i<9;i++){
        fscanf(in,"%d",&informat[i]);
        informat[i]=4-informat[i]/3;
        for (k=0;k<informat[i];k++)
            for (p=0;p<9;p++) opneed[p]+=table[i][p];
    }
    
    int flag=0;
    for (i=0;i<9;i++) 
        for (k=0;k<opneed[i]%4;k++)
            if (!flag) {fprintf(out,"%d",i+1); flag=1;} 
            else fprintf(out," %d",i+1);
    fprintf(out,"\n");
    return 0;
}