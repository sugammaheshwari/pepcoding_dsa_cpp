
#include<iostream>
#include<vector>
using namespace std;


double exp(double x, int n)
{
    if(n==0) return 1;
    // using bitwise operation to find odd power!
    if(n&1) return x*exp(x,n-1);    // odd power case
    else return exp(x*x, n/2);      // even power
}

// it also handles negetive powers
// good solution!!!

double myPow(double x, int n) {
    if(abs(x)==1) return (n%2==0)?1.0:x;
    if(n==INT_MIN) return 0.0;
    if(n>=0) return exp(x, n);
    else return 1/exp(x,abs(n));
    }
};
