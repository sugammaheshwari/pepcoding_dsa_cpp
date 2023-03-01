/*
 Imagine you have a special keyboard with the following keys:
 Key 1:  Prints 'A' on screen
 Key 2: (Ctrl-A): Select screen
 Key 3: (Ctrl-C): Copy selection to buffer
 Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

 Input:
 The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the number of key.

 Output:
 Print maximum number of A's. Print -1, if N is greater than 75.

 Constraints:
 1 ≤ T ≤ 50
 1 ≤ N ≤ 75

 Example:
 Input:
 2
 3
 7

 Output:
 3
 9
 */

#include<iostream>
#include<vector>
using namespace std;

int get_count(int n)
{
    if(n<=6)
        return n;
    
    vector<int> dp(n);
    for(int i=1;i<=6;i++)
        dp[i-1]=i;
    
    for(int i=7;i<=n;i++)
        dp[i-1]=max(2*dp[i-4],max(3*dp[i-5],4*dp[i-6]));
    
    return dp[n-1];
}

int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        cout<<get_count(n)<<endl;
    }
    
    return 0;
}
