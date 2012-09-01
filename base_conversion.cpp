#include <iostream>
#include <cmath>

using namespace std;

int final[99];

void convert_base(int number, int base){
	
	double remainder;
    
	int i=0;
	while (number !=0){
		remainder=(number%base);
		final[i]=remainder;
		i++;
		number=number/base;
	}

	int j=i;

	// check if number is a palindrome --
	cout << i << endl;
	if(true){
		for (i--; i>-1; i--){
			if (final[i]<10)
				cout<<final[i];
			else
				cout<<char(final[i]-10+'a');
		}
	}
		
}

int main()
{

	convert_base(21,10);




	return 0;
} 
