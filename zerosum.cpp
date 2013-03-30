/*
ID: manubha1
PROG: zerosum
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <set>
#include <sstream>
#include <algorithm>
#include <stack>
#include <assert.h>

#include <memory.h>

#ifdef _WIN32
#include <time.h>
#endif

using namespace std;

#ifdef _WIN32
typedef __int64 n64;
typedef unsigned __int64 u64;
#else
typedef long long n64;
typedef unsigned long long u64;
#endif

#if !defined( _WIN32 )
#define _itoa itoa

char * itoa( int _Val, char * _DstBuf, int _Radix)
{
    sprintf( _DstBuf, "%d", _Val );
    return _DstBuf;
}

#endif

std::string conv(int decimal, int base){
    if(decimal == 0) return "0";
    char NUMS[] = "0123456789ABCDEF"; // Characters that may be used
    std::string result = ""; // Create empty string ready for data to be appended
    do{
        result.push_back(NUMS[decimal%base]);
        // Append the appropriate character in NUMS based on the equation decimal%base
        
        decimal /= base; // Calculate new value of decimal
    }while(decimal != 0); // Do while used for slight optimisation
    
    return std::string(result.rbegin(), result.rend());
    // using std::string() constructer with iterators to reverse the string
}



bool check(string s){
    stack<int> st ;
    assert(st.empty());
    int length = s.length();
    // cout <<  "length" << length << endl;
    st.push(1);

    for(int i=2;i<=length+1;i++){
        if(s[i-2]=='0'){
            int t = st.top();
            st.pop();
            st.push(t*10+i);            
        }
        else if(s[i-2]=='1'){
            st.push(-1);
            st.push(i);
        }
        else{
            st.push(-2);
            st.push(i);


            
        }
    }

    // cout << st.size() << endl;

    int ans = 0;
    while(st.size()>1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        

        if(b==-1){
            ans = ans+ a;
        }
        else if(b==-2){
            ans  = ans-a;
            
        }
    }
    ans = ans+st.top();
    if(ans==0){
        return true;
    }

    return false;
}


string out(char c){
    if(c=='0'){
        return " ";
    }
    if(c=='1'){
        return "+";
    }
    if(c=='2'){
        return "-";
    }
}



int main(){
        
    ifstream fin("zerosum.in");
    ofstream fout("zerosum.out");
    int n;
    fin >> n;
    int i=0;
    string s="";
    int limit = pow(3,n-1);
    char c[3];
    c[0]=' ';
    c[1]='+';
    c[2]='-';
    while(i<limit){
        s = conv(i,3);
        int len = s.length();
        if(len<n-1){
            for(int i=0;i<(n-1 - len);i++){
                s = "0"+s;
            }
        }
        
        if(check(s)){


            for(int j=1;j<n;j++){
                fout << j <<out(s[j-1]);
            }
            fout << n << endl;
        }
        i++;
    }

    


}











