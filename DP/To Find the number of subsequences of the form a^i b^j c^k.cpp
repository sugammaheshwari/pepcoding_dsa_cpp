
/*
    To Find the number of subsequences of the form a^i b^j c^k.
    
 Given a string, count number of subsequences of the form aibjck, i.e., it consists of i ’a’ characters, followed by j ’b’ characters, followed by k ’c’ characters where i >= 1, j >=1 and k >= 1.
 
 example :
 
 Input  : abbc
 Output : 3
 Subsequences are abc, abc and abbc

 Input  : abcabc
 Output : 7
 Subsequences are abc, abc, abbc, aabc
 abcc, abc and abc
 
 */

#include<iostream>
using namespace std;

int ways(string s)
{
    int empty_ways=1;
    int a_Ways=0;
    int b_Ways=0;
    int c_Ways=0;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a')
            a_Ways= a_Ways + (empty_ways + a_Ways);     // (exclude + include) ways
        
        if(s[i]=='b')
            b_Ways= b_Ways + (a_Ways + b_Ways);
        
        if(s[i]=='c')
            c_Ways= c_Ways + (b_Ways + c_Ways);
    }
    return c_Ways;
}



int main()
{
    string s="abcabc";
    cout<<ways(s);
}
