/*
ID: manubha1
PROG: namenum
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

typedef vector<string> string_arr;

map<char,char> m1;


string gen(string s){
	string num = "";
	for(int i=0;i<s.length();i++){
		num.append(1,m1[s.at(i)]);
	}
	return num;
}


int main(){

	

	m1['A']='2';
	m1['B']='2';
	m1['C']='2';
	m1['D'] = '3';
	m1['E'] = '3';
	m1['F'] = '3';
	m1['G'] = '4';
	m1['H'] = '4';
	m1['I'] = '4';
	m1['J'] = '5';
	m1['K'] = '5';
	m1['L'] = '5';
	m1['M'] = '6';
	m1['N'] = '6';
	m1['O'] = '6';
	m1['P'] = '7';
	m1['R'] = '7';
	m1['S'] = '7';
	m1['T'] = '8';
	m1['U'] = '8';
	m1['V'] = '8';
	m1['W'] = '9';
	m1['X'] = '9';
	m1['Y'] = '9';

	ifstream fdict("dict.txt");
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");


	// first read in the dictionary and store it in a set.

	string s;
	map<string, string_arr> dict;
	string p;
	while((fdict >> s) != NULL){
		string num;
		num = gen(s);
		if(dict.find(num) == dict.end()){
			dict[num] = string_arr();
		}
		dict[num].push_back(s);
	}

	string q ;
	fin >> q;

	if(dict.find(q)!=dict.end()){
		string_arr arra = dict[q];
		sort(arra.begin(),arra.end());
		for(int k=0;k<arra.size();k++){
			fout << arra[k] << endl;
		}
	}
	else{
		fout << "NONE" << endl;
	}


}