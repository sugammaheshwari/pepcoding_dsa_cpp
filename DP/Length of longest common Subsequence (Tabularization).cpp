
/*
    Q: To find the length of longest common subsequence in the given two strings.
 
 for our two string
 
 The DP table formed by recurssion is:
4:3:3:2:2:0:0:0:
4:3:3:2:2:1:1:0:
0:3:3:2:2:1:1:0:
0:3:3:2:2:1:1:0:
0:2:2:2:2:1:1:0:
0:1:1:1:1:1:1:0:
0:0:0:0:0:0:0:0:

The Dp table Formed By tabularization is :
4:3:3:2:2:1:1:0:
4:3:3:2:2:1:1:0:
4:3:3:2:2:1:1:0:
3:3:3:2:2:1:1:0:
2:2:2:2:2:1:1:0:
1:1:1:1:1:1:1:0:
0:0:0:0:0:0:0:0:

IMP THING TO NOTICE !!!

Noitce here in column 1 the 5 values are different , its not ki our answer is wrong its like
tabularization works by filling the whole table and recurrsion only works and fills the table for the required calls
so the zeros in recurssion dp represent these calls were not made !!!

*/




#include<iostream>
#include<vector>
using namespace std;

string f_ans;

// BY RECURSSION
int common_Subsequence(string s1,string s2,int s1_sidx,int s2_sidx,vector<vector<int>> &dp,string ans)
{
    if(s1_sidx==s1.length() || s2_sidx==s2.length())
    {
        if(f_ans.length()<ans.length())
            f_ans=ans;
        return 0;
    }

    if(dp[s1_sidx][s2_sidx]!=0)
        return dp[s1_sidx][s2_sidx];
    
    if(s1[s1_sidx]==s2[s2_sidx])
        return dp[s1_sidx][s2_sidx]=1 + common_Subsequence(s1,s2,s1_sidx+1,s2_sidx+1,dp,ans+s1[s1_sidx]);
    
    return dp[s1_sidx][s2_sidx]=max(common_Subsequence(s1,s2,s1_sidx+1,s2_sidx,dp,ans),
                                    common_Subsequence(s1,s2,s1_sidx,s2_sidx+1,dp,ans));
}



// BY TABULIZATION
int common_subsequence_DP(string s1,string s2)
{
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    
    for(int i=int(s1.length()-1);i>=0;i--)
    {
        for(int j=int(s2.length()-1);j>=0;j--)
        {
            if(s1[i]==s2[j])
                dp[i][j]=dp[i+1][j+1]+1;
            else
                dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    return dp[0][0];
    
}


int main()
{
    string s1="AGGTAB";
    string s2="GXTXAYB";
    
    cout<<common_subsequence_DP(s1,s2);
    
}
