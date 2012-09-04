/*
ID: manubha1
PROG: pprime
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


using namespace std;


int length(int num){
	int ans =0 ;
	while(num > 0){
		num = num/10;
		ans++;
	}
	return ans;
}

bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

int reverseNumber(int num){
    int rev=0;
    while(num>0){
        rev = 10*rev + (num%10);
        num = num/10;
    }
    return rev;
}

int genPalindrom(int num, bool k){
    int len = length(num);
    int pal;
    if(k){
        pal = num*pow(10,len) + reverseNumber(num);
    }
    else{
        int k = num/10;
        pal = num*pow(10,len-1)+ reverseNumber(k);
    }
    return pal;
}


int main(){
		
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	int a,b,ma,mi,tmp;
	fin >> a >> b;

    int lenA = length(a);
    int lenB = length(b);
    vector<int> v;

    if(lenB%2==1){
       tmp = b;
    }
    else{
        tmp = pow(10,lenB-1) -1 ;

    }
    ma = tmp/(pow(10,(length(tmp)/2)));


    if(lenA%2==1){
        tmp = pow(10,lenA-1) -1;
    }
    else{
        tmp = a;
    }
    mi = tmp / (pow(10,(length(tmp)/2)));
    

    for(int i=mi;i<=ma ;i++){
        tmp = genPalindrom(i,false);

        if(tmp>=a && tmp <=b){
            if(isPrime(tmp)){
                v.push_back(tmp);
            }
        }
        tmp = genPalindrom(i,true);
        if(tmp>=a && tmp <=b){
            if(isPrime(tmp)){
                v.push_back(tmp);
            }
        }

    }

    sort(v.begin(),v.end());

    for(tmp = 0 ;tmp<v.size();tmp++){
        fout << v[tmp] << endl;
    }
	
	 
	


}