

// Target sum using recurssion and dynamic programming !!!

#include<iostream>
#include<vector>
using namespace std;

int target_sum(vector<int> &nums,int idx,int target,vector<vector<int>> &dp)
{
    if(idx==nums.size() || target==0)
        return dp[idx][target]=target==0?1:0;
    
    int count=0;
    if(target-nums[idx]>=0)
        count+=target_sum(nums,idx+1,target-nums[idx],dp);
    
    count+=target_sum(nums,idx+1,target,dp);
    return dp[idx][target]=count;
}

// This is the best way to fill the Dp by tabularization method
// Other way ie filling from bottom right to upper left increases complexity of the code

int targetSum_DP(vector<int> &arr,int tar,vector<vector<int>> &dp)
{
    dp[0][0]=1;

    for(int idx=1;idx<dp.size();idx++){
        for(int t=0;t<=tar;t++){
               
            int count=0;
            if(t-arr[idx-1]>=0){
                count+=dp[idx-1][t-arr[idx-1]];
            }
            count+=dp[idx-1][t];
            
            dp[idx][t]=count;
        }
    }

    return dp[dp.size()-1][dp[0].size()-1];
}



int main()
{
    vector<int> nums={1,3,5,7,2,9};
    int target=8;
    vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,0));
    
    //cout<<target_sum(nums,0,target,dp)<<endl;
    
    cout<<targetSum_DP(nums,target,dp)<<endl;
    
    for(auto x:dp)
    {
        for(auto c:x)
            cout<<c<<":";
        cout<<endl;
    }
    
}
