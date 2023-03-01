/*
LEETCODE : 152. Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

beautiful youtube explanation : https://www.youtube.com/watch?v=0exOBHgzApE&t=675s

 */

// Q2 : Maximum subarray sum : https://www.youtube.com/watch?v=KPU8-J4Vtfk&t=886s

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>> dp(n);
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                dp[0].first=nums[0];dp[0].second=nums[0];
                ans=max(ans,nums[0]);
                continue;
            }
            dp[i].first=min(nums[i],min(dp[i-1].first*nums[i],dp[i-1].second*nums[i]));                      //represents min product subarray ending at index i
            dp[i].second=max(nums[i],max(dp[i-1].first*nums[i],dp[i-1].second*nums[i]));                    // represents max product subarray ending at index i
            ans=max(ans,dp[i].second);
        }
        
        return ans;
    }
};


//  Maximum subarray sum


int max_sum_subarray(vector<int> &nums)
{

    vector<int> dp(n);
    int ans=INT_MIN;
    dp[0]=nums[0];

    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        ans=max(ans,dp[i]);
    }

    return ans;
}
