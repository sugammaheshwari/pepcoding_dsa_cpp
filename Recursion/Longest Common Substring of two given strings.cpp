
// To Find the length of longest Common Substring in the two given strings
/*
 
 
 DP table using recurssion:
 
   q`u`i`z`g`e`e`k`s`
 g`0:0:0:0:5:0:0:0:0:
 e`0:0:0:0:0:4:1:0:0:
 e`0:0:0:0:0:1:3:0:0:
 k`0:0:0:0:0:0:0:2:0:
 s`0:0:0:0:0:0:0:0:1:
 f`0:0:0:0:0:0:0:0:0:
 o`0:0:0:0:0:0:0:0:0:
 r`0:0:0:0:0:0:0:0:0:
 g`0:0:0:0:5:0:0:0:0:
 e`0:0:0:0:0:4:1:0:0:
 e`0:0:0:0:0:1:3:0:0:
 k`0:0:0:0:0:0:0:2:0:
 s`0:0:0:0:0:0:0:0:1:
 
 
 */

#include<iostream>
#include<vector>
using namespace std;

int max_len=0;

int len_longest_common_substring(string s1,string s2,int i,int j,vector<vector<int>> &dp)
{
    if(i==s1.length() || j==s2.length())
        return 0;
    
    if(dp[i][j]!=0)
        return dp[i][j];
    
    int a=0;
    if(s1[i]==s2[j]){
        a=1+len_longest_common_substring(s1,s2,i+1,j+1,dp);
        max_len=max(max_len,a);
    }
    
    len_longest_common_substring(s1,s2,i+1,j,dp);
    len_longest_common_substring(s1,s2,i,j+1,dp);
    
    return dp[i][j]=a;
}

int main()
{
    string s1="geeksforgeeks",s2="quizgeeks";
    vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),0));
    
    len_longest_common_substring(s1,s2,0,0,dp);
    cout<<"the length of longest common substring is:"<<max_len<<endl;
    
    for(auto x:dp)
    {
        for(auto v:x)
            cout<<v<<":";
        cout<<endl;
    }
}
