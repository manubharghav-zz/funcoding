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

void print(int *v){
	for(int i=0;i<9;i++){
		cout << v[i] << "  " ;
	}
	cout << endl;
}




int main(){
		
	ifstream fin("clocks.in");
	ofstream fout("clocks.out");

	int tmp;
	
	for(int i=0;i<9;i++){
		fin >> tmp;

		v[i]=(tmp%12);
	}
	vector<int> ans;
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout << v[i] << "  ";
	// }

	// cout << endl;

	// doo(&v,moves[0]);

	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout << v[i] << "  ";
	// }
	// cout << endl;

	int tmp1=0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0;  k< 4; k++)
			{
				for (int l = 0;  l< 4; l++)
				{
					for (int  m= 0;  m< 4; m++)
					{
						for (int  n= 0;  n< 4; n++)
						{
							for (int o = 0;  o< 4; o++)
							{
								for (int p = 0; p < 4; p++)
								{
									for (int  q= 0;  q< 4; q++)
									{
										string s = "";

										for(int it = 0;it<9;it++){
											sample[it] = v[it];
										}
										for(tmp1=0;tmp1<q;tmp1++){
											s.push_back('1');
											doo(sample,moves[0]);
										}
										for(tmp1=0;tmp1<p;tmp1++){
											s.push_back('2');
											doo(sample,moves[1]);
										}

										for(tmp1=0;tmp1<o;tmp1++){
											s.push_back('3');
											doo(sample,moves[2]);
										}
										for(tmp1=0;tmp1<n;tmp1++){
											s.push_back('4');
											doo(sample,moves[3]);
										}
										for(tmp1=0;tmp1<m;tmp1++){
											s.push_back('5');
											doo(sample,moves[4]);	
										}
										for(tmp1=0;tmp1<l;tmp1++){
											s.push_back('6');
											doo(sample,moves[5]);
										}
										for(tmp1=0;tmp1<k;tmp1++){
											s.push_back('7');
											doo(sample,moves[6]);
											
										}
										for(tmp1=0;tmp1<j;tmp1++){
											s.push_back('8');
											doo(sample,moves[7]);
											
										}
										for(tmp1=0;tmp1<i;tmp1++){
											s.push_back('9');
											doo(sample,moves[8]);
										
										}

										if(check(sample)){
											ans.push_back(atoi(s.c_str()));
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

	sort(ans.begin(),ans.end());
	string Result;         // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << ans[0];      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	int tmp3 = Result.size();
	for(int i=0;i<tmp3-1;i++){
		fout << Result.at(i) << " " ;
	}
	fout << Result.at(tmp3-1) << endl;



	// int tmp3;
	// while(tmp2>0){
	// 	tmp3 = tmp2%10;
	// 	tmp2 = tmp2/10;
	// 	ans1.push_back(tmp3);
	// }

	// for(int i=ans1.size() - 1;i>0;i--){
	// 	fout << ans1[i] << " ";
	// }

	// fout << ans1[0] << endl;

}

