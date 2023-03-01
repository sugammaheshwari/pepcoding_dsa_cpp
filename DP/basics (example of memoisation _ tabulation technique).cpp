
#include<iostream>
#include<vector>
using namespace std;

// memoization method for dp

int fibo_dp(int n,vector<int> &dp)
{
    if(n==0 || n==1)
        return n;
    
    if(dp[n]!=0)
        return dp[n];
    
    int ans=fibo_dp(n-1,dp) +fibo_dp(n-2,dp);
    dp[n]=ans;
    return ans;
}

// tabulation method for dp

int fibo_tabulation_dp(int N,vector<int> &dp)
{
    for(int i=0;i<N;i++)
    {
        if(N==0 || N==1)
        {
            dp[N]=N;
            continue;
        }
        
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[N-1];
}

void display(vector<int> v)
{
    cout<<endl;
    for(auto x:v)
        cout<<x<<":";
    cout<<endl;
}

