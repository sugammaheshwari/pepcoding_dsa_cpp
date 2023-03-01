
// DP - 14: Partition Set into two Subset such that Subset Sum have Minimum Difference
/*
 
 Beatiful quesstion simple extension of target sum subset problem
 first find out the regular target sum ( sum(array)/2) as we want to partition array into two equal halves.
 
 then try to find the highest possible target value which is true in the dp table and caculate and return your ans!
 
 */


#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &v)
{
    int sum=0;
    for(auto x:v)
        sum+=x;
    
    int target=sum/2;
    
    vector<vector<bool>> dp(v.size()+1,vector<bool>(target+1));
    for(int i=1;i<=target;i++)
        dp[0][i]=0;
    for(int i=0;i<=v.size();i++)
        dp[i][0]=1;
    
    for(int i=1;i<=v.size();i++)
    {
        for(int t=1;t<=target;t++)
        {
            if( dp[i-1][t] || (t-v[i-1]>=0 && dp[i-1][t-v[i-1]]) )
               dp[i][t]=1;
        }
    }
               
    for(int i=target;i>=0;i--)
        if(dp[v.size()][i])
            return sum-2*i;
    
    return -1;
}



int main()
{
    vector<int> v={1,6,5,11};
    cout<<"the min diff is:"<<find(v);
}
