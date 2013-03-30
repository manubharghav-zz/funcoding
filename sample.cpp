#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <fstream> // alternative output method
//#include <algorithm> // sorting functions and binary search
//#include <utility> // pair
using namespace std;
int N, sum = 0;
int main()
{
// you can also use ifstream and ofstream
// but those are slower
FILE * input = fopen("easyprob.in", "r");
FILE * output = fopen("easyprob.out", "w");
fscanf(input, "%d", &N);
for(int i = 0; i < N; i++)
{
int x;
fscanf(input, "%d", &x);
sum += x;
}
fprintf(output, "%d\n", sum);
fclose(input);
fclose(output);
return 0;
}