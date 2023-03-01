
/*
 
GEEKS :  Subset Sum Problem | DP-25
 also called target sum subset
 also applied in 0/1 knapsack !!!
 Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
NOTE : here its important that the set contains non-negetive integers !!!

 Each state in DP represents best answer possible with or without me (ie nums[i-1]) for dp[i][target]
 
 here basically we are optimising the method of finding all the possible subsets ( which could have taken 2^n recursive calls)
 here instead we built a dp[n][target] and found the best possible answer by bulding upon the previous state's best possible answer.
  
 */

#include<iostream>
#include<vector>
using namespace std;

bool sub_Set_DP(vector<int> &nums,int target)
{
    vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1));
    for(int i=0;i<=nums.size();i++)
        dp[i][0]=1;
    for(int i=1;i<=target;i++)
        dp[0][i]=0;
    
    for(int i=1;i<=nums.size();i++)
        for(int t=1;t<=target;t++)
        {
            if( dp[i-1][t] || (t-nums[i-1]>=0 && dp[i-1][t-nums[i-1]]) )
                dp[i][t]=1;
            else
                dp[i][t]=0;
        }

    //  output of the table formed !!!
    
    for(auto x:dp)
    {
        for(auto y:x)
            cout<<y<<":";
        cout<<endl;
    }
    
    return dp[nums.size()][target];
}




int main()
{
    // example 1:
    //         i pushed 0 (int the begenning to make index computation easier
//    vector<int> nums={0,3,34,4,12,5,2};
//
//    int target=30;
  
    // example 2
    vector<int> nums= {1,2,5};
    int target=4;
    
    if(sub_Set_DP(nums,target))
        cout<<"yes";
    else
        cout<<"no";
}
