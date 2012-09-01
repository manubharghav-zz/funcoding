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


int main(){
		
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	int a,b,c,d;
	fin >> a >> b;

	c = a/pow(10,max((length(a)/2)-(length(a)%2),1));
	d = b/pow(10,(length(b)/2));


	cout << c << "  " << d<< endl;
	 
	


}