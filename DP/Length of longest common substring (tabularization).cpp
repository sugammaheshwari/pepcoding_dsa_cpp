
/*
 
 To Find the length of longest Common Substring in the two given strings

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
 
 Dp table using tabulization :
 0:0:0:0:5:0:0:0:0:0:
 0:0:0:0:0:4:1:0:0:0:
 0:0:0:0:0:1:3:0:0:0:
 0:0:0:0:0:0:0:2:0:0:
 0:0:0:0:0:0:0:0:1:0:
 0:0:0:0:0:0:0:0:0:0:
 0:0:0:0:0:0:0:0:0:0:
 0:0:0:0:0:0:0:0:0:0:
 0:0:0:0:5:0:0:0:0:0:
 0:0:0:0:0:4:1:0:0:0:
 0:0:0:0:0:1:3:0:0:0:
 0:0:0:0:0:0:0:2:0:0:
 0:0:0:0:0:0:0:0:1:0:
 0:0:0:0:0:0:0:0:0:0:
 
 here in dp table for tabulization we needed extra row and column because we were building answer from bottom right corner towards upper left ,side by side filling the table !
 
 this table cleary explains why in recurrsion we needed max_ans to store the max_len  for substring cause its not the case that aur first recursive call will fetch us the ans ( or in tabular terms that our answer will be for surley located at [0][0] cell
 
 Good work !!!!
 
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


int long_common_substring_tab(string s1,string s2)
{
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    int max_len=0;
    
    for(int i=int(s1.length())-1;i>=0;i--)
    {
        for(int j=int(s2.length())-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i+1][j+1]+1;
                max_len=max(max_len,dp[i][j]);
            }
        }
    }
    
    return max_len;
}

int main()
{
    string s1="geeksforgeeks",s2="quizgeeks";
    
    cout<<"the length of longest common substring is:"<<long_common_substring_tab(s1,s2)<<endl;
        
}
