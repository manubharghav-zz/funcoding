/*
ID: manubha1
PROG: transform 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int n;

using namespace std;

typedef vector< vector<char> > vec_char;
void rot_90(vec_char *c1,vec_char *c2){
     int i,k;
     for (i=0;i<(*c1).size();i++){
     	
         for (k=0;k<(*c1).size();k++){
             (*c2)[k][n-1-i]=(*c1)[i][k];
             
         }
     }
}


bool same(vec_char c1, vec_char c2){
	int i,k;
	for (i=0;i<c1.size();i++){
         for (k=0;k<c1.size();k++){
             if(c1[i][k]!=c2[i][k]){
             	return false;
             }
         }
     }
     return true;
}


void reflect(vec_char *c1, vec_char *c2){
	int i,k;
	for(i=0;i<(*c1).size();i++){
		for(k=0;k<(*c1).size();k++){
			(*c2)[i][n-k-1] = (*c1)[i][k];
		}		
	}
}

void copy(vec_char *c1, vec_char *c2){
	int i,k;
	for (i=0;i<(*c1).size();i++){
         for (k=0;k<(*c1).size();k++){
             (*c1)[i][k]=(*c2)[i][k];
             }
         
     }
     
}




void print(vec_char c1){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout <<  c1[i][j] ;
		}
		cout << endl;
	}

}

int main(){
		
	ifstream fin("transform.in");
	ofstream fout("transform.out");



	fin >> n;
	vec_char orig(n);
	vec_char final(n);
	vec_char temp1(n);
	vec_char temp2(n);

	char tmp;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin >> tmp;
			orig[i].push_back(tmp);
			temp1[i].push_back(tmp);
			temp2[i].push_back(tmp);
			
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin >> tmp;
			final[i].push_back(tmp);

		}
	}


	
	int i=1;

	for(i=1;i<4;i++){
		rot_90(&temp1, &temp2);
		if(same(temp2, final)){
			fout << i << endl;
			return 0;
		}
		else{
			copy(&temp1, &temp2);
		}

	}
	i=4;
	reflect(&orig, &temp1);
	if(same(final,temp1)){
		fout << i << endl;
		return 0;
	}
	else{

		for(i=1;i<4;i++){
		rot_90(&temp1, &temp2);

		if(same(temp2, final)){
			fout << 5 << endl;
			return 0;
		}

		else{
			copy(&temp1,&temp2);
		}

	}

	}

	if(same(orig,final)){
		fout << 6 << endl;
		return 0;
	}


	fout << 7 << endl;
	return 0;

	


}