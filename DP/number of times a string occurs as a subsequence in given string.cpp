
/*
  
 Q: Find number of times a string occurs as a subsequence in given string.
 
 Q link : https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
 
 DP table filled by recurssion :
 4:0:0:0:
 1:3:0:0:
 1:3:0:0:
 1:3:0:0:
 1:1:2:0:
 1:1:1:1:
 1:1:1:0:
 1:1:1:0:
 1:1:1:0:
 0:1:1:0:
 0:1:1:0:
 0:1:1:0:
 0:0:1:0:
 0:0:0:1:
 
 DP table filled by Tabularization :
 
 4:3:2:1:
 1:3:2:1:
 1:3:2:1:
 1:3:2:1:
 1:1:2:1:
 1:1:1:1:
 1:1:1:1:
 1:1:1:1:
 1:1:1:1:
 0:1:1:1:
 0:1:1:1:
 0:1:1:1:
 0:0:1:1:
 0:0:0:1:
 
 */


#include<iostream>
#include<vector>
using namespace std;

int func(int i,int j,string s1,string s2,vector<vector<int>> &dp)
{
    if(j==s2.length())
        return dp[i][j]=1;
    if(i==s1.length())
        return dp[i][j]=0;
    
    int count=0;
    
    if(s1[i]==s2[j])
        count+=func(i+1,j+1,s1,s2,dp);
    count+=func(i+1,j,s1,s2,dp);
    
    return dp[i][j]=count;
}

int func_tabular(string s1,string s2,vector<vector<int>> &dp)
{
    
    for(int j=int(s2.length());j>=0;j--)
    {
        for(int i=int(s1.length());i>=0;i--)
        {
            if(j==s2.length())
            {
                dp[i][j]=1;
                continue;
            }
            else if(i==s1.length())
                dp[i][j]=0;
            else if(s1[i]==s2[j])
                dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
            else
                dp[i][j]=dp[i+1][j];
        }
    }
    
    for(auto x:dp)
    {
        for(auto c:x)
            cout<<c<<":";
        cout<<endl;
    }
    
    return dp[0][0];
}


void run_func()
{
    string s1="geeksforgeeks";
    string s2="gks";
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    cout<<"\n the no of possible strings are :"<<func(0,0,s1,s2,dp)<<endl;
    
    for(auto v:dp)
    {
        for(auto x:v)
            cout<<x<<":";
        cout<<endl;
    }

}

int main()
{
    string s1="geeksforgeeks";
    string s2="gks";
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    cout<<func_tabular(s1,s2,dp);
}
