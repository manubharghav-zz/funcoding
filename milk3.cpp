/*
ID: manubha1
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>

using namespace std;

set<int> solution_set;
bool check[21][21][21];

class node{
	public:
		int a;
		int b;
		int c;

		node(int p,int q, int r):a(p),b(q),c(r){
		}
};


void solve(int a,int b, int c){

	deque<node> q;
	q.push_back(node(0,0,c));
	check[0][0][c] = true;
	while(!q.empty()){
		node n = q.front();
		q.pop_front();

		if(n.a == 0){
			solution_set.insert(n.c);
		}
		int new_a,new_b,new_c;
		//c->b
		new_a = n.a;
		if(n.b + n.c >= b){
			new_b = b;
			new_c = n.b + n.c - b;
		}
		else{
			new_b = n.b+n.c;
			new_c = 0;
		}
		if(!(check[new_a][new_b][new_c])){
			q.push_back(node(new_a,new_b,new_c));
			check[new_a][new_b][new_c]=true;
		}



		// c->a

		new_b = n.b;
		if(n.c + n.a >= a){
			new_a = a ;
			new_c = n.a + n.c - a;
		}
		else{
			new_a = n.a+n.c;
			new_c = 0;
		}
		if(!(check[new_a][new_b][new_c])){
			q.push_back(node(new_a,new_b,new_c));
			check[new_a][new_b][new_c]=true;
		}



		// b->a

		new_c = n.c;
		if(n.b + n.a >= a){
			new_a = a;
			new_b = n.b + n.a - a;
		}
		else{
			new_a = n.a+n.b;
			new_b = 0;
		}
		if(!(check[new_a][new_b][new_c])){
			q.push_back(node(new_a,new_b,new_c));
			check[new_a][new_b][new_c]=true;
		}



		// b->c
		new_a = n.a;
		if(n.b + n.c >= c){
			new_c = c;
			new_b = n.b + n.c - c;
		}
		else{
			new_c = n.c+n.b;
			new_b = 0;
		}
		if(!(check[new_a][new_b][new_c])){
			q.push_back(node(new_a,new_b,new_c));
			check[new_a][new_b][new_c]=true;
		}



		// a->b

		new_c = n.c;
		if(n.a + n.b >= b){
			new_b = b;
			new_a = n.a + n.b - b;
		}
		else{
			new_b= n.b+n.a;
			new_a = 0;
		}
		if(!(check[new_a][new_b][new_c])){
			q.push_back(node(new_a,new_b,new_c));
			check[new_a][new_b][new_c]=true;
		}




		// a->c
		new_b = n.b;
		if(n.a + n.c >= c){
			new_c = c;
			new_a = n.a + n.c - c;
		}
		else{
			new_c = n.c+n.a;
			new_a = 0;
		}
		if(!(check[new_a][new_b][new_c])){
			q.push_back(node(new_a,new_b,new_c));
			check[new_a][new_b][new_c]=true;
		}
	}



}



int main(){


	for(int i=0;i<20;i++){
		for(int j=0;j<=20;j++){
			for(int k=0;k<=20;k++){
				check[i][j][k] = false;

			}
		}
	}
		
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	int a,b,c;



	fin >> a >>b >>c ;

	solve(a,b,c);


	set<int>::iterator it;
	it=solution_set.begin();
	for ( int i=0 ; i<solution_set.size()-1; i++ ){
    	fout << *it << " ";
    	it++;
    }

  	fout <<*it << endl;


}