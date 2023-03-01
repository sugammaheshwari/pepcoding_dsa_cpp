

// Q1: To find longest Palindromic Substring using DP
// Q2: TO find longest Palindromic Subsequence using DP


#include<iostream>
#include<vector>
using namespace std;
 
string s="forgeeksskeegfor";
vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));

int longest_palindromic_Substring(string s)
{
    int max_len=0;
    
    for(int gap=0;gap<s.length();gap++)
    {
        for(int i=0,j=gap;j<s.length();i++,j++)
        {
            if(gap==0)
                dp[i][j]=1;
            else if(s[i]==s[j] && gap==1)
                dp[i][j]=2;
            else if(s[i]==s[j] && dp[i+1][j-1]!=0)
                dp[i][j]=2+dp[i+1][j-1];
            
            if(dp[i][j]!=0)                             // this condition helps to check and update max_len for LPS
                max_len=max(max_len,dp[i][j]);
        }
    }
    
    return max_len;
}

/*
 // To find longest Palindromic substring ( The actual string , not only length)
 // Using tabularization method !!
 
 string s="abccbb";
 vector<vector<string>> dp(s.length(),vector<string>(s.length(),""));

 Cheers !!!
 */
string longest_palindromic_Substring_02(string s,vector<vector<string>> &dp)
{
    int l=int(s.length());
    string ans;
    
    for(int gap=0;gap<l;gap++)
    {
        for(int i=0,j=gap;j<l;j++,i++)
        {
            if(gap==0)
                dp[i][j].push_back(s[i]);
            else if(s[i]==s[j] && gap==1){
                dp[i][j].push_back(s[i]);
                dp[i][j].push_back(s[j]);}
            else if(s[i]==s[j] && dp[i+1][j-1].length()!=0){
                dp[i][j].push_back(s[i]);
                dp[i][j].append(dp[i+1][j-1]);
                dp[i][j].push_back(s[j]);}
        
            if(dp[i][j].length()>ans.length())
                ans=dp[i][j];
        }
    }
    
    return ans;
}


int longest_palindromic_Subsequence(string s)
{
    for(int gap=0;gap<s.length();gap++)
    {
        for(int i=0,j=gap;j<s.length();j++,i++)
        {
            if(gap==0)
                dp[i][j]=1;
            else if(s[i]==s[j])
                dp[i][j]=2+dp[i+1][j-1];
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][s.length()-1];
}


void run_longest_palindromic_Substring()
{
    cout<<"the length of longest palindromic substring is :"<<longest_palindromic_Substring(s)<<endl;
    
    for(auto x:dp)
    {
        for(auto y:x)
            cout<<y<<":";
        cout<<endl;
    }
}

void run_longest_palindromic_Subsequence()
{
    cout<<"the length of longest palindromic subsequence is :"<<longest_palindromic_Subsequence(s)<<endl;
    
    for(auto x:dp)
    {
        for(auto y:x)
            cout<<y<<":";
        cout<<endl;
    }
}

int main()
{
    //run_longest_palindromic_Substring();
    run_longest_palindromic_Subsequence();
}


/*
 
 To find length of longest palindromic subtstring in a string , here is the recursive code:
 
 bool check(string s,int sidx,int eidx)
 {
     while(sidx<=eidx)
         if(s[sidx++]!=s[eidx--])
             return false;
     return true;
 }

 int len(string s,int sidx,int eidx)
 {
     if(sidx==eidx)
         return 1;
     if(sidx>eidx)
         return 0;
     if(s[sidx]==s[eidx] && check(s,sidx,eidx))
         return eidx-sidx+1;
     
     return max(len(s,sidx+1,eidx),len(s,sidx,eidx-1));
 }


 happy to help !!!
 */
