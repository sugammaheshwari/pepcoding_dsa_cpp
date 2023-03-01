
/*
 
To find the number of possible ways to climb staircase of n stairs
 with at max 2 steps allowed ie: 1 or 2 steps can be taken to reach the top !
 */


#include<iostream>
#include<vector>
using namespace std;


// Recursive Solution : more inutitve solution !

int climb_stairs(int n)
{
    if (n<=1)
        return 1;
    
    return climb_stairs(n-1) + climb_stairs(n-2);
}

// climb stairs using DP !

int climb_stairs_(int n,vector<int> &dp)
{
    if(n<=1){
        dp[n]=1;
        return 1;
    }
    
    return climb_stairs_(n-1, dp) + climb_stairs_(n-2, dp);
}



// Pepcoding's Optimised Method !
int climb_stairs_Optimised(int n)
{
    if(n<=1)
        return 1;
    
    int a=1;
    int b=1;
    int ans=1;
    
    for(int i=2;i<=n;i++)
    {
        ans=a+b;
        a=b;
        b=ans;
        
    }
    return ans;
}

int main()
{
    int n=4;
    vector<int> dp(n+1,0);
    cout<<climb_stairs_Optimised(n);
    
    cout<<climb_stairs_(n,dp);
}
