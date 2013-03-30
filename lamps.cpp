/*
ID: manubha1
PROG: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

int lamps[16][100];
int C;
set<int> solutions;

void apply(int n,int * lamp){
	switch(n)
	{
		case 1:
			// cout <<"manu" << endl;
			for(int i=0;i<100;i++){
				if(lamp[i]==1){
					lamp[i]=0;
				}
				else{
					lamp[i]=1;
				}
			}
			break;
		case 2:
			for(int i=0;i<100;i=i+2){
				if(lamp[i]==1){
					lamp[i]=0;
				}
				else{
					lamp[i]=1;
				}
			}
			break;
		case 3:
			for(int i=1;i<100;i=i+2){
				if(lamp[i]==1){
					lamp[i]=0;
				}
				else{
					lamp[i]=1;
				}
			}
			break;
		case 4:
			for(int i=0;i<100;i=i+3){
				if(lamp[i]==1){
					lamp[i]=0;
				}
				else{
					lamp[i]=1;
				}
			}
			break;
		default:
			break;

	}
}



void generate(){
	solutions.insert(0);
	if(C==0){return;}

	apply(1,lamps[1]);
	// cout << lamps[1][0] << endl;
	solutions.insert(1);
	apply(2,lamps[2]);
	solutions.insert(2);
	apply(3,lamps[3]);
	solutions.insert(3);
	apply(4,lamps[4]);
	solutions.insert(4);
	if(C==1){return;}
	apply(1,lamps[5]);apply(2,lamps[5]);
	solutions.insert(5);
	apply(1,lamps[6]);apply(3,lamps[6]);
	solutions.insert(6);
	apply(1,lamps[7]);apply(4,lamps[7]);
	solutions.insert(7);

	apply(2,lamps[8]);apply(3,lamps[8]);
	solutions.insert(8);
	apply(2,lamps[9]);apply(4,lamps[9]);
	solutions.insert(9);
	apply(3,lamps[10]);apply(4,lamps[10]);
	solutions.insert(10);
	if(C==2){return;}
	apply(1,lamps[11]);apply(2,lamps[11]);apply(3,lamps[11]);
	solutions.insert(11);
	apply(1,lamps[12]);apply(2,lamps[12]);apply(4,lamps[12]);
	solutions.insert(12);
	apply(1,lamps[13]);apply(3,lamps[13]);apply(4,lamps[13]);
	solutions.insert(13);
	apply(2,lamps[14]);apply(3,lamps[14]);apply(4,lamps[14]);
	solutions.insert(14);
	if(C==3){return;}
	apply(1,lamps[15]);apply(2,lamps[15]);apply(3,lamps[15]);apply(4,lamps[15]);
	solutions.insert(15);	


}





int main(){
		
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	int N;

	fin >>N;
	fin >> C;



	for(int i=0;i<16;i++){
		for(int j=0;j<100;j++){
			lamps[i][j]=1;
		}
	}

	generate();

	int j;
	int on = 1;

	while((fin >>j)!=NULL){
		if( j==-1){on =0;}
		else{

			for(int i=0;i<16;i++){
				if(lamps[i][j-1]!=on){
					solutions.erase(i);
				}
			}
		}
	}


	if(solutions.size()==0){
		fout << "IMPOSSIBLE" << endl;
		return 0;
	}

	set<int>::iterator it;
	set<string> sol_sort;
	for(it = solutions.begin();it!=solutions.end();it++){
		int sol = *it;
		std::stringstream ss ;
		
		for(int i=0;i<N;i++){
			ss<<lamps[sol][i];
		}

		sol_sort.insert(ss.str());
	}


	set<string>::iterator sol_it = sol_sort.begin();
	for(sol_it=sol_sort.begin();sol_it!=sol_sort.end();sol_it++){
		fout << *sol_it << endl;
	}
	




	// for(int i=0;i<16;i++){
	// 	for(int j=0;j<10;j++){
	// 		cout << lamps[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	









	


}




// solution:
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <assert.h>

// #define MAXLAMP	6
// #define LAMPMASK	((1<<MAXLAMP)-1)

// int nlamp;
// int nswitch;
// int ison;
// int known;

// int poss[1<<MAXLAMP];

// int flip[4] = {
//     LAMPMASK,		/* flip all lights */
//     LAMPMASK & 0xAA, 	/* flip odd lights */
//     LAMPMASK & 0x55,	/* flip even lights */
//     LAMPMASK & ((1<<(MAXLAMP-1))|(1<<(MAXLAMP-4)))	/* lights 1, 4 */
// };

// /*
//  * Starting with current light state ``lights'', flip exactly n switches
//  * with number >= i.
//  */
// void
// search(int lights, int i, int n)
// {
//     if(n == 0) {
// 	if((lights & known) == ison)
// 	    poss[lights] = 1;
// 	return;
//     }

//     for(; i<4; i++)
// 	search(lights ^ flip[i], i+1, n-1);
// }

// void
// printseq(FILE *fout, int lights)
// {
//     int i;
//     char s[100+1];

//     for(i=0; i<nlamp; i++)
// 	s[i] = (lights & (1<<(MAXLAMP-1 - i%MAXLAMP))) ? '1' : '0';
//     s[nlamp] = '\0';
//     fprintf(fout, "%s\n", s);
// }

// void
// main(void)
// {
//     FILE *fin, *fout;
//     int a, i, impossible;

//     fin = fopen("lamps.in", "r");
//     fout = fopen("lamps.out", "w");
//     assert(fin != NULL && fout != NULL);

//     fscanf(fin, "%d %d", &nlamp, &nswitch);

//     for(;;) {
// 	fscanf(fin, "%d", &a);
// 	if(a == -1)
// 	    break;
// 	a = MAXLAMP-1 - (a-1) % MAXLAMP;
// 	ison |= 1<<a;
// 	known |= 1<<a;
//     }

//     for(;;) {
// 	fscanf(fin, "%d", &a);
// 	if(a == -1)
// 	    break;
// 	a = MAXLAMP-1 - (a-1) % MAXLAMP;
// 	assert((ison & (1<<a)) == 0);
// 	known |= 1<<a;
//     }

//     if(nswitch > 4)
// 	if(nswitch%2 == 0)
// 	    nswitch = 4;
// 	else
// 	    nswitch = 3;

//     for(; nswitch >= 0; nswitch -= 2)
// 	    search(LAMPMASK, 0, nswitch);

//     impossible = 1;
//     for(i=0; i<(1<<MAXLAMP); i++) {
// 	if(poss[i]) {
// 	    printseq(fout, i);
// 	    impossible = 0;
// 	}
//     }
//     if(impossible)
// 	fprintf(fout, "IMPOSSIBLE\n");

//     exit(0);
// }
