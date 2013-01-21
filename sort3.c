// /*
// ID: manubha1
// PROG: sort3
// LANG: C++
// */

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <map>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <math.h>
// #include <queue>

// using namespace std;
// int n;
// int store[1000];
// int co[3];
// map< int, vector<int> > o;
// typedef vector<int> vec;

// //previous code.
// // vector<int> s;
// // 	int N,tmp,tmp1;
// // 	fin >> N;
// // 	int ans=0;
// // 	fin >> tmp;
// // 	s.push_back(tmp);

// // 	for(int i=1;i<N;i++){
// // 		fin >> tmp;
// // 		// insert tmp into the s at correct location.
// // 		s.push_back(tmp);
// // 		for(int j=0;j<s.size()-2;j++){
// // 			if(s[j]<tmp){
// // 				continue;
// // 			}
// // 			else{
// // 				if(s[s.size()-1]>tmp){
// // 					tmp1 = s[j];
// // 					s[j] = s[s.size()-1];
// // 					s[s.size()-1] = tmp1;
// // 					ans++;
// // 				}
// // 				else{

// // 				}
// // 			}
// // 		}
// // 	}
// void swap1(int tmp, int index){
// 	// if(tmp==3 && index ==3){
// 	// 	cout << "debugging" << endl;
// 	// }
// 	if(tmp==2 || (tmp==3 && co[0]>0)){

// 		int pos = o[0].back();
		
// 		o[0].pop_back();
// 		//sort(o[0].begin(),o[0].end());
// 		o[tmp-1][0] = pos;
// 		sort(o[tmp-1].begin(),o[tmp-1].end());
// 		store[pos]=tmp;
// 		store[index]=1;
// 		co[0]--;

// 	}
// 	else{

// 		int pos = o[1].back();
// 		// cout << pos << endl;
// 		// o[1][0] = o[1].back();
// 		o[1].pop_back();
// 		// sort(o[1].begin(),o[1].end());
// 		o[tmp-1][0] = pos;
// 		sort(o[tmp-1].begin(),o[tmp-1].end());
// 		store[pos]=tmp;
// 		store[index]=2;
// 		co[1]--;
// 	}
// }

// void print(){
// 	for(int i=0;i<n;i++){
// 		cout << store[i] << "  ";
// 	}

// 	cout << endl;
// }

// int main(){
		
// 	ifstream fin("sort3.in");
// 	ofstream fout("sort3.out");

// 	for(int i=0;i<2;i++){
// 		co[i]=0;
// 		o[i]= vec();
// 	}
	
// 	fin >> n;
// 	int tmp;
// 	for (int i=0;i<n;i++){
// 		fin>>tmp;
// 		co[tmp-1]=co[tmp-1]+1;
// 		o[tmp-1].push_back(i);
// 		store[i]=tmp;
// 	}
	
// 	int ans = 0;

// 	for(int i=0;i<n;i++){
// 		tmp = store[i];
// 		if(tmp==1 || (tmp==2 && co[0]==0) || (tmp ==3 && co[0]==0 && co[1]==0)) {
// 			co[tmp-1]--;
// 			o[tmp-1][0] = o[tmp-1].back();
// 			o[tmp-1].pop_back();
// 			sort(o[tmp-1].begin(),o[tmp-1].end());
// 			continue;
// 		}
// 		else {
// 			// cout << tmp <<"  "<< i << endl;
// 			swap1(tmp,i);
// 			// if (tmp==3 && i==3){print();return 0;}
// 			ans++;
// 		}
// 		// print();
// 	}
// 	fout << ans << endl;
// 	//start the menace.

// }

#include <algorithm>
#include <stdio.h>
 
int main() {
    int i, j, t, n, res = 0, c1 = 0, c2 = 0, a[1000];
 
    FILE *in = fopen("sort3.in", "r");
    fscanf(in, "%d", &n);
 
    for (i = 0; i < n; i++) {
        fscanf(in, "%d", &a[i]);
        if (a[i] == 1)
            ++c1;
        else if (a[i] == 2)
            ++c2;
    }
    fclose(in);
 
    for (i = c1; i < n; i++) {
        if (a[i] == 1) {
            for (j = t = 0; j < c1; j++) {
                if (a[j] == 2) {
                    t = j;
                    break;
                } else if (a[j] == 3) {
                    t = j;
                }
            }
            std::swap(a[i], a[t]);
            ++res;
        }
    }
 
    for (i = c1 + c2; i < n; i++)
        if (a[i] == 2)
            ++res;
 
    FILE *out = fopen("sort3.out", "w");
    fprintf(out, "%d\n", res);
    fclose(out);
    return 0;
}