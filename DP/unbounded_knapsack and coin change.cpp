
/*
    Unbounded Knapsack and coin change problem
    both very similar questions uses 1-d DP
 
  coin change : https://leetcode.com/problems/coin-change/
 
 */

#include<iostream>
#include<vector>
using namespace std;

long coinChange(vector<int>& coins, int amount)
{
    vector<long> dp(amount+1,INT_MAX);
    dp[0]=0;
    
    for(int a=1;a<=amount;a++)
    {
        long ans=INT_MAX;
        for(auto c:coins)
            if(a-c>=0)
                ans=min(ans,dp[a-c]+1);
        dp[a]=ans;
    }
    
    return dp[amount]>=INT_MAX?-1:dp[amount];
}

int unbounded_knapsack(vector<int> &val,vector<int> &wt,int limit)
{
    vector<int> dp(limit+1,0);
    
    for(int l=1;l<=limit;l++)
    {
        for(int i=0;i<wt.size();i++)
        {
            if(l-wt[i]>=0)
            {
                dp[l]=max(dp[l],val[i]+dp[l-wt[i]]);
            }
        }
    }
    
    return dp[limit];
}

int main()
{
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    
    cout<<unbounded_knapsack(val,wt,7);
}
