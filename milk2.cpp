/*
ID: manubha1
PROG: milk2
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;


struct myclass {
  bool operator() (pair<int,int> i,pair<int,int> j) {
  	if(i.first < j.first){
  		return true;
  	}
  	else if(i.first==j.first){
  		return (i.second<j.second);
  	}
  	else{
  		return false;
  	}
  	}
} myobject;


int main(){

	ifstream fin("milk2.in");
	ofstream fout("milk2.out");


	int n;
	fin >> n;

	vector<pair<int,int> > v;


	int x,y;
	for(int i=0;i<n;i++){

		fin >>x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end(),myobject);

	int lci_start=0,lci_end=0,lci = 0,luci=0;

	for(int i=0;i<v.size();i++){
		
		
		if(lci_end != 0 && v[i].first <= lci_end){
			if(v[i].second > lci_end){
				lci_end = v[i].second ;
			}
		}
		else{
			if(lci_end- lci_start > lci){
				lci = lci_end - lci_start;
			}

			if(i>0 && v[i].first - lci_end > luci ){
				luci = v[i].first - lci_end;
			}

			lci_start = v[i].first;
			lci_end = v[i].second;

			if(lci_end - lci_start> lci){
				lci = lci_end - lci_start;
				
			}
		}
	}

	fout << lci << " " << luci << endl;
	// start the parse
}
