/*
ID: manubha1
PROG: milk 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


class unit
{
public:
	int x,y;
	unit(int a,int b):x(a),y(b){};

	friend bool operator < (const unit& m1, const unit& m2)
    {
        return (m1.x <= m2.x) ? true : false;
    }
    friend bool operator == (const unit& m1, const unit& m2)
    {
        return (m1.x == m2.x) ? true : false;
    }

	/* data */
};





int main(){
		
	ifstream fin("milk.in");
	ofstream fout("milk.out");


	set< unit > m;


	int N,M,tmp1,tmp2;
	fin >> N >> M;

	for(int i=0;i<M;i++){

		fin >> tmp1 >> tmp2;
		m.insert(unit(tmp1,tmp2));
	}
	set<unit> ::iterator it = m.begin();
	int cost=0;

	while(it!=m.end() && (N>0)){
		// decide how much to take from this farmer.
		//cout << (*it).x << "   " << (*it).y << endl;
		if (N>=((*it).y)){
			cost = cost + ((*it).x * ((*it).y));
			N = N-((*it).y);
		}

		else{
			cost = cost + ((*it).x * (N));
			//cout << (*it).x <<"   " << (*it).y << "  " << N <<endl;
			N=0;


		}


		it++;
	}

	
	fout << cost << endl;
}