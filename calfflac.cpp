/*
ID: manubha1
PROG: calfflac
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



class unit{
	char c;
	int pos;

	unit(char c_1, int pos_1):c(c_1),pos(pos_1){
	}
};


string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
string longestPalindromeSimple(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}


int main(){
		
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	string s="";
	string tmp;
	while(getline(fin,tmp)!=NULL){
		s+=tmp;
		s+='\n';
	}
	// strip the unecesary charectors from the string.
	string pal="";
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		if(isalpha(s[i])){
			pal+=tolower(s[i]);
			v.push_back(i);
		}

	}

	string long_palindrome = longestPalindromeSimple(pal);
	



	int pos = pal.find(long_palindrome);
	int start_pos = v[pos];
	int end_pos = v[pos+(long_palindrome.size())-1];
	fout << long_palindrome.size() << endl;
	string ans = s.substr(start_pos,(end_pos-start_pos)+1);
	fout << ans << endl;
	




}