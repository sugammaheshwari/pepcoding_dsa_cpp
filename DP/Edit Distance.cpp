
// GEEEKS : EDIT DISTANCE PROBLEM
// Link : https://www.geeksforgeeks.org/edit-distance-dp-5/

#include<iostream>
#include<vector>
using namespace std;

int edit_dis(string &s1,string &s2)
{
   
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1));
    
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
        }
    }
    
    return dp[s1.size()][s2.size()];
}


int main()
{
    string s1="horse",s2="ros";
    
    cout<<edit_dis(s1,s2);

    
}

