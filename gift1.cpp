/*
ID: manubha1
PROG: gift1
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;
int main()
{	
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	vector<string> sequence;
	map<string, int> account;

	int NP,i,amount,num,tmp1,tmp2;
	fin >> NP;
	string s,t;
	for(i=0;i<NP;i++){
		fin >> s;
		sequence.push_back(s);
		account[s]=0;
	}

	for(i=0;i<NP;i++){
		fin >> s; // giver
		fin >> amount >> num;
		if (num!=0){
			tmp1 = amount/num;		
			tmp2 = amount - (amount%num);
			account[s] = account[s]-tmp2;
			for(int j=0;j<num;j++){
				fin >> t;
				account[t] = account[t]+ tmp1;
			}
		}	
	}

	for(i=0;i<sequence.size();i++){

		fout << sequence[i] << " " << account[sequence[i]]<< endl;
	}
	return 0;
}