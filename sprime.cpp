/*
ID: manubha1
PROG: sprime
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

set <int> primes;

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


bool prime(int num){

	if(primes.find(num)== primes.end()){
		if(isPrime(num)){
			primes.insert(num);
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}


int main(){
		
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");


	// cout << prime(2333) << endl;

	int N;

	fin >> N;

	int s  =(int) pow(10,N-1);
	int b =(int) pow(10,N) - 3;
	bool start = false;
	for(int i=s;i<=b;i){

		for(int j=N-1;j>=0;j--){
			if(prime((int)i/(int)pow(10,j))){
				if(j==0){
					// if(start){
					// 	fout << endl ;

					// }
					// start = true;
					fout << i << endl;
					i++;

				}
			}
			else{
				i = i+pow(10,j);
				break;
			}
		}


	}

}