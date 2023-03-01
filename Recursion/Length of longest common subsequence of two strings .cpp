
#include<iostream>
#include<vector>
using namespace std;

string f_ans;

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


int main()
{
    string s1="AGGTAB";
    string s2="GXTXAYB";
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    
    cout<<"the length of maximum common subsequence from two given strings is:"<<common_Subsequence(s1,s2,0,0,dp,"")<<endl;
    
    cout<<"\n The DP table formed is as follows ::"<<endl;
    for(auto v:dp)
    {
        for(auto x:v)
            cout<<x<<":";
        cout<<endl;
    }
    
    cout<<"\n The string is :"<<f_ans<<endl;
    return 1;
}
