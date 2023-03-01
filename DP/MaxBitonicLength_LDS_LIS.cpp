
// Q1 : Longest increasing 'Subsequence'
// Q2 : Longest Decreasing Subsequence
// Q3 : Longest Bitonic Sequence
// Q4 : Maximum sum increasing Subsequence
// Q5 : Minimum no of deletion to make an array sorrted

#include<iostream>
#include<vector>
using namespace std;

// Longest Increasing Subsequence

int len_longest_inc_subsequece(vector<int> &arr,vector<int> &dp)
{
    int g_max=0;
    for(int i=0;i<arr.size();i++)           // stores longest subsequence till this index including itself !
    {
        int max_len=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
                max_len=max(max_len,dp[j]);
        }
        max_len+=1;
        dp[i]=max_len;
        g_max=max(g_max,dp[i]);
    }
    return g_max;
}

// Longest Decresing subsequence

int len_longest_dec_subsequece(vector<int> &arr,vector<int> &dp)
{
    int g_max=0;
    for(int i=int(arr.size()-1);i>=0;i--)
    {
        int max_len=0;
        for(int j=i+1;j<int(arr.size());j++)
        {
            if(arr[i]>arr[j])
                max_len=max(max_len,dp[j]);
        }
        max_len+=1;
        dp[i]=max_len;
        g_max=max(g_max,dp[i]);
    }
    return g_max;
}

/*
Longest Bitonic Subsequence
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic
if it is first increasing, then decreasing.

Example : Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)
*/

int longest_bitonic_sequence(vector<int> &arr)
{
    vector<int> dp_LIS(arr.size());
    vector<int> dp_LDS(arr.size());
    
    len_longest_inc_subsequece(arr,dp_LIS);
    len_longest_dec_subsequece(arr,dp_LDS);
    
    int max_bitonic_len=0;
    
    for(int i=0;i<int(arr.size());i++)
        max_bitonic_len=max(max_bitonic_len,dp_LIS[i]+dp_LDS[i]-1);
    // here -1 is because in bitonic length the current element occurs twice
    // once in LDS and once in LIS // Imp point to notice !!!
    
    return max_bitonic_len;
}


// To find maximum sum of increasing Subsequences.
// Simple Variation of LIS (Longest Increasing Subsequence )

int Max_sum_inc_subsequence(vector<int> &arr,vector<int> &dp)
{
    int g_max=0;
    for(int i=0;i<arr.size();i++)
    {
        int max_sum=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
                max_sum=max(max_sum,dp[j]);
        }
        max_sum+=arr[i];
        dp[i]=max_sum;
        g_max=max(g_max,dp[i]);
    }
    return g_max;
}

// Minimum no of deletion to make an array sorted ?
// LOGIC - find LIS with equal to sign and then subtract the answer with the no of elements in the given array !

int min_no_del(vector<int> &arr,vector<int> &dp)
{
    int g_max=0;
    for(int i=0;i<arr.size();i++)
    {
        int max_len=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>=arr[j])                              // * here equal to '=' is added where as in regular LIS there is no equal to !!!
                max_len=max(max_len,dp[j]);
        }
        max_len+=1;
        dp[i]=max_len;
        g_max=max(g_max,dp[i]);
    }
    return arr.size()-g_max;
}


void LDS_main()
{
    vector<int> arr={ 10, 22, 9, 33, 21, 50, 41, 60,80 };
    vector<int> dp(arr.size(),0);
    
    cout<<"\n The longest Decreasing subsequence is:"<<len_longest_dec_subsequece(arr,dp)<<endl;
    
    for(int i=0;i<dp.size();i++)
    {
            cout<<arr[i]<<":"<<dp[i]<<endl;
    }
}

void Bitonic_main()
{
   // LDS_main();
    vector<int> arr={1, 11, 2, 10, 4, 5, 2, 1};
    cout<<longest_bitonic_sequence(arr)<<endl;
}

int main()
{
    Bitonic_main();
}
