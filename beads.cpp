/*
ID: manubha1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

char prev_char;
int left_max;
int left_int(int n, int x){

	if (x==0){
		return n-1;
	}
	else{
		return x-1;
	}
}



int right_int(int n,int x){
	return (x+1)%n ;
}



int func_left(string s,int n, int pos1){

	int iter=0;

	int left = 1;
	int pos = left_int(n,pos1);
	iter ++;
	if(s[pos]=='w'){
		pos = left_int(n,pos);
		iter ++;
		while(s[pos]=='w' && iter < n){
			pos = left_int(n,pos);
			left++;
			iter++;
		}
		prev_char = s[pos];
		left++;
		pos = left_int(n,pos);
		iter++;
		while(s[pos]==prev_char && iter <= n){
		pos = left_int(n,pos);
		iter ++;
		left++;
		}

		left_max = pos;
	}
	else if(s[pos]=='b'){
		prev_char= s[pos];
		pos = left_int(n,pos);
		iter ++;
		while(s[pos]!='r' && iter <= n){
			pos = left_int(n,pos);
			left++;
			iter++;
		}
		left_max = pos;
	}
	else{
		prev_char= s[pos];
		pos = left_int(n,pos);
		iter ++;
		while(s[pos]!='b' && iter <= n){
			pos = left_int(n,pos);
			left++;
			iter++;
		}
		left_max = pos;
	}

	return left;

}



int func_right(string s,int n, int pos1){

	int iter=1;
	int right = 1;
	int pos = pos1;
	if(s[pos]=='w'){
		pos = right_int(n,pos);
		iter ++;
		while(s[pos]=='w' && iter <= n){
			pos = right_int(n,pos);
			right++;
			iter ++;
		}
		prev_char= s[pos];
		right++;
		pos = right_int(n,pos);
		iter ++;
		while(s[pos]==prev_char && iter <= n){
		pos = right_int(n,pos);
		iter ++;
		right++;
		}
	}
	else if(s[pos]=='b'){
		prev_char= s[pos];
		pos = right_int(n,pos);
		iter ++;
		while(s[pos]!='r' && iter <= n){
			pos = right_int(n,pos);
			iter ++;
			right++;
		}

	}
	else{
		prev_char= s[pos];
		pos = right_int(n,pos);
		while(s[pos]!='b' && iter <= n){
			pos = right_int(n,pos);
			right++;
		}
	}

	return right;

}

int main(){


	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n;
	fin >> n;
	string s;
	fin >> s;


	

	//boundary case.
	int curr = 0;
	int prev = 0;
	int ans = 0;
	
	int extreme_left = func_left(s,n,0);
	curr = curr  +extreme_left;
	if(curr >= n){fout<< curr << endl; return 0;}
	for(int i=0;i<n;i++){
		if((s[i]==prev_char || s[i]=='w') && i <= left_max){
			curr++;
		}
		else{

			prev_char = s[i];
			if(curr + prev > ans){ ans = curr+prev;}
			prev = curr;
			curr = 1;
		}

	}
	int left_over = func_right(s,n,n-1);
	if(left_over==1){prev_char == s[n-1];}
	curr = curr-1+left_over;
	if(curr + prev > ans){ ans = curr+prev;}
	// pass from the other side.
	curr = 0;
	prev = 0;
	curr = curr + left_over;
	for(int i = n-2;i>=0;i--){
		if(s[i]==prev_char || s[i]=='w'){
			curr++;
		}
		else{
			prev_char = s[i];
			if(curr + prev > ans){ ans = curr+prev;}
			prev = curr;
			curr = 1;
		}
	}
	left_over = func_left(s,n,1);
	curr = curr-1+left_over;
	if(curr + prev > ans){ ans = curr+prev;}
	fout << ans << endl;
	return 0;
}