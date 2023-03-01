
//Q1: To find longest Palindromic Subsequence using Recurrsion.
//Q1: To find count of number of palindromic subsequences of the given string.
// NOte : This problem is Better Solved Using DP !!

#include<iostream>
using namespace std;

string final_ans;


int palindromic_subsequence(string str,int s,int e)
{
    if(s==e)
        return 1;
    if(s>e)
        return 0;
    if(str[s]==str[e])
        return 2 + palindromic_subsequence(str,s+1,e-1);
    
    return max(palindromic_subsequence(str,s+1,e),palindromic_subsequence(str,s,e-1));
}

int countOfPalindromicSubsubsequence_Rec(string str,int si,int ei,vector<vector<int>> &dp)
{
   if(si>ei)
       return 0;
   if(si==ei)
       return dp[si][ei]=1;

   if(dp[si][ei]!=0)
       return dp[si][ei];

    int middleString=countOfPalindromicSubsubsequence_Rec(str,si+1,ei-1,dp);
    int withoutFirstCharString=countOfPalindromicSubsubsequence_Rec(str,si+1,ei,dp);
    int withoutLastCharString=countOfPalindromicSubsubsequence_Rec(str,si,ei-1,dp);

    int rAns=withoutFirstCharString + withoutLastCharString;
    
    return dp[si][ei]=(str[si]==str[ei])? (rAns + 1) : (rAns - middleString);
}


int main()
{
    string s="geekedes";
    int sidx=0;
    int eidx=int(s.length()-1);
    
    cout<<"the length of Longest palindromic_subsequence is:"<<palindromic_subsequence(s,sidx,eidx)<<endl;
}
