/*
ID: manubha1
PROG: barn1
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


class unit
{
public:
	int x,y,z;
	unit(int a,int b):x(a),y(b){z = b-a+1;}

	friend bool operator < (const unit& m1, const unit& m2)
    {
        return (m1.z <= m2.z) ? true : false;
    }
    friend bool operator == (const unit& m1, const unit& m2)
    {
        return (m1.z == m2.z) ? true : false;
    }

	/* data */
};


int main(){
		
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	

	int M,C,S,tmp;

	fin >> M >> S >> C;

	// get the gaps

	int ig =1;
	int ans = C;

	set<unit> s;
	vector<int> v;


	for(int i=0;i<C;i++){
		fin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(),v.end());
	vector<int>::iterator it1 = v.begin();
	while(it1!=v.end()){
		tmp = *it1;
		if (tmp == ig){
			ig = ig+1;
		}
		else if(tmp > ig){
			if (ig!=1){
				s.insert(unit(ig,tmp-1));
			}
			ig = tmp +1;
		}

		it1++;
	}


	set<unit>::iterator it = s.begin();
	
	while(s.size()>=M){
		it = s.begin();
		ans = ans + (*it).z ;
		s.erase(it);
	}

	fout << ans << endl;

	return 0;


}