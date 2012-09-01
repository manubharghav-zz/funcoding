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


string moves[] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int sample[9] = {0,0,0,0,0,0,0,0,0} ;

int v[9] = {0,0,0,0,0,0,0,0,0};


bool check(int *v){	
	for(int i=0;i<9;i++){
		if (v[i]!=0){
			return false;
		}
	}
	return true;
}


void doo(int * v,string s){
	int c;
	for(int i=0;i<s.size();i++){
		c = ((int)s.at(i)) - 65;
		v[c] = (v[c]+3)%12;
	}
}

bool check1(int *sample,int move){
	int c = 0;
	while(move > 0){
		c = move%10;
		move = move/10;
		doo(sample,moves[c-1]);
	}
	if (check(sample)){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ifstream fin("clocks.in");
	ofstream fout("clocks.out");

	int tmp;
	
	for(int i=0;i<9;i++){
		fin >> tmp;

		v[i]=(tmp%12);
	}


	for(int i=0;i<=9;i++){
		for(int j=i;j<=9;j++){
			for(int k=j;k<=9;k++){
				for(int l=k;l<=9;l++){
					for(int m=l;m<=9;m++){
						for(int n=m;n<=9;n++){
							for(int o=n;o<=9;o++){
								for(int p=o;p<=9;p++){
									for(int q=p;q<=9;q++){
										int count  = q+10*p+100*o+ 1000*n+10000*m+100000*l + 1000000*k + 10000000*j + 100000000*i;
										for(int it = 0;it<9;it++){
											sample[it] = v[it];
										}

										if(check1(sample,count)){
											string Result;         // string which will contain the result
											ostringstream convert;   // stream used for the conversion
											convert << count;      // insert the textual representation of 'Number' in the characters in the stream

											Result = convert.str();
											int tmp3 = Result.size();
											for(int i=0;i<tmp3-1;i++){
												fout << Result.at(i) << " " ;
											}
											fout << Result.at(tmp3-1) << endl;
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}




}
