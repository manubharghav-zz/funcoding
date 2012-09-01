/*
ID: manubha1
PROG: packrec 
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



class rec{
public:
	int len;
	int bre;
	rec(int x,int y):len(x),bre(y){

	}
};


class ans{
public:
	int len;
	int bre;
	int area;
	ans(int x,int y):len(x),bre(y){
		area = len*bre ;
	}

};

int max(int a,int b)
{
	return (a>b)?a:b;
}
int max3(int a, int b, int c)
{
	return max(max(a,b),c);
}
int max4(int a,int b, int c, int d)
{
	return max(max(max(a,b),c),d);
}


bool myfunction (ans i,ans j) { return (i.bre < j.bre); }

void rotate(vector<rec> * v , int i){

	int tmp = (*v)[i].len;
	(*v)[i].len = (*v)[i].bre;
	(*v)[i].bre = tmp;
}

bool check(vector<ans> *a, int len, int wid){

	for(int i=0;i<(*a).size();i++){
		if((*a)[i].len == len || (*a)[i].bre == len){
			return false;
		}
	}

	return true;
}


int main(){
		
	ifstream fin("packrec.in");
	ofstream fout("packrec.out");

	vector<rec> v;

	int x,y;
	for(int i=0;i<4;i++){
		fin >> x >>y ;
		v.push_back(rec(max(x,y),min(x,y)));
	}


	vector<ans> an;


	// layout 1

	int length;
	int width;

	an.push_back(ans(10000,10000));
	// layout 2

	int i,j,k,l;
	int m,n,o,p;
    
    
    for(i=0;i<4;i++){
    	for(m=0;m<2;m++){
    		rotate(&v,i);
        	for(j=0;(j<4);j++){
        		if( j==i){continue;}
        		for(n=0;n<2;n++){
        			rotate(&v,j);
        			for(k=0;(k<4);k++){
        				if(k==i || k == j){continue;}
        				for(o=0;o<2;o++){
        					rotate(&v,k);
        					for(l=0;(l<4);l++){
        						if(l==i || l==j || l==k){continue;}
        						for(p=0;p<2;p++){
        							rotate(&v,l);

        							// layout 1;

        							length  = v[i].bre + v[j].bre + v[k].bre +v[l].bre;
									width = max(max(v[i].len,v[j].len),max(v[k].len,v[l].len));

									if (an[0].area >= (length*width)){
										if (an[0].area > (length*width)){
											an.clear();
										}
										if(check(&an, length,width)){
											an.push_back(ans(max(length,width),min(length,width)));
										}
									}



				     //                length = (v[i].bre)+ max(max((v[j].len),(v[k].len)),v[l].len);
									// width = max(v[i].len, (v[j].bre + v[k].bre + v[l].bre));

									int length=max(v[i].len,v[j].bre+v[k].bre+v[l].bre);
									int width=v[i].bre+max3(v[j].len,v[k].len,v[l].len);

									if (an[0].area >= (length*width)){
										if (an[0].area > (length*width)){
											an.clear();
										}
										if(check(&an, length,width)){
											an.push_back(ans(max(length,width),min(length,width)));
										}
									}

								// layout 3

									// length = max(v[j].len,(max(v[k].len, v[l].len) + v[i].bre));
									// width = max(((v[j].bre)+v[i].len) , (v[j].bre + v[k].bre + v[l].bre));\
									length = v[l].bre+max(v[i].len,v[j].bre+v[k].bre);
									width = max(v[l].len , v[i].bre+max(v[j].len,v[k].len));

									if (an[0].area >= (length*width)){
										if (an[0].area > (length*width)){
											an.clear();
										}
										if(check(&an, length,width)){
											an.push_back(ans(max(length,width),min(length,width)));
										}
									}
									 //cout <<"layout 3"<< "  "<< length << "  " <<width << endl;



								// layout 4

									length = v[i].bre+max(v[j].bre,v[k].bre)+v[l].bre;
									width = max3(v[i].len,v[j].len+v[k].len,v[l].len);

									if (an[0].area >= (length*width)){
										if (an[0].area > (length*width)){
											an.clear();
										}
										if(check(&an, length,width)){
											an.push_back(ans(max(length,width),min(length,width)));
										}
									}
									 //cout<<"layout 4" << "  " << length << "  " <<width << endl;

								// layout 5


									width = max(v[i].bre,v[j].bre) + v[k].bre+v[l].bre;
									length = max3(v[i].len+v[j].len,v[k].len,v[l].len);

									if (an[0].area >= (length*width)){
										if (an[0].area > (length*width)){
											an.clear();
										}
										if(check(&an, length,width)){
											an.push_back(ans(max(length,width),min(length,width)));
										}
									}
									// layout 6
									//cout <<"layout 5" << "  "<< length << "  " <<width << endl;

									
									width=v[i].bre+v[l].bre;

									if (v[i].len<v[l].len)
										width=max(v[i].bre+v[l].bre,v[j].bre+v[l].bre);
									if (v[i].len+v[j].len>v[l].len)
										width=max(width,v[j].bre+v[k].bre);
									if (v[i].len>v[l].len)
										width=max(width,v[i].bre+v[k].bre);
									width=max(max(width,v[j].bre),v[k].bre);

									length = max(v[i].len+v[j].len,v[k].len+v[l].len);


									if (an[0].area >= (length*width)){
										if (an[0].area > (length*width)){
											an.clear();
										}

										if(check(&an, length,width)){
											an.push_back(ans(max(length,width),min(length,width)));
										}
									}

								

								}
							}
						}
					}
					// 	

                } 
            } 
        }
    }
	
    sort(an.begin(),an.end(),myfunction);
    fout << an[0].area << endl;
    for(int i=0;i<an.size();i++){
    	fout << an[i].bre << " " << an[i].len << endl;
     }
	
	return 0;
}