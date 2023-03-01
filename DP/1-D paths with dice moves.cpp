
/*
 
 To  find all possible paths in a 1-d array
 array with 10 cells with the six possible moves of the dice
 using dp and tabulation method !
 
 */



#include<iostream>
#include<vector>
using namespace std;

int paths_DP(int start,int end,vector<int> &dp)
{
    if(start==end)
    {
        dp[start]=1;
        return 1;
    }
    
    int count=0;
    
    if(dp[start]!=0)
        return dp[start];
    
    for(int i=1;i<=6;i++)
        if(start+i<=end)
            count+=paths_DP(start+i,end,dp);
    
    dp[start]=count;
    return count;
}


int paths_tabulation(int start,int end,vector<int> &dp)
{
    
    for(int i=end;i>=start;i--)
    {
        if(i==end)
        {
            dp[i]=1;
            continue;
        }
    
        int count=0;
    
        for(int j=1;j<=6;j++)
            if(i+j<=end)
                count+=dp[i+j];

        dp[i]=count;
    }
    
    return dp[0];
}


int main()
{
    vector<int> dp(10,0);
    cout<<paths_tabulation(0,9,dp)<<endl;

    for(auto x:dp)
        cout<<x<<":";
}
