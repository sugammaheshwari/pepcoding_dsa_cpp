
/*
 
 0-1 Knapsack Problem | DP-10
 
 0/1 knapsack using tabularization Method
 IMPORTANT QUESTION !!!
 
 bsically we can extend this method when we are trying to generate all the possible subsets for the given set !!
 
 NOTE : this method would not be optional when target or here in 0/1 knapsack case limit is very high
 
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int> val={ 15,14,10,45,30};
vector<int> wt={ 2, 5, 1,3,4 };


int main()
{
    int n=int(val.size());
    int limit=7;
    
    vector<vector<int>> dp(n+1,vector<int>(limit+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=limit;w++)
        {
            dp[i][w]=dp[i-1][w];
            if(w-wt[i-1]>=0)
            {
                dp[i][w]=max(dp[i][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }
        }
    }
    
    for(auto x:dp)
    {
        for(auto y:x)
            cout<<y<<":";
        cout<<endl;
    }
    
    cout<<"answer for 0/1 knapsack is :";
    cout<<dp[n][limit]<<endl;
}
