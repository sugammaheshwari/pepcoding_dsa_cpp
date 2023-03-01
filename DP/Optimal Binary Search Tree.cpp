
/*
    ****** Optimal Binary Search Tree | DP-24 ******
 
 Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i].
  Find a binary search tree of all keys such that the total cost of all the searches is as small as possible.
 
 Example:
 Input:  keys[] = {10, 12}, freq[] = {34, 50}
 There can be following two possible BSTs
         10                       12
           \                     /
            12                 10
           I                     II
 Frequency of searches of 10 and 12 are 34 and 50 respectively.
 The cost of tree I is 34*1 + 50*2 = 134
 The cost of tree II is 50*1 + 34*2 = 118


 Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
 There can be following possible BSTs
     10                12                 20         10              20
       \             /    \              /             \            /
       12          10     20           12               20         10
         \                            /                 /           \
          20                        10                12             12
      I               II             III             IV             V
 Among all possible BSTs, cost of the fifth BST is minimum.
 Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142
 
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int> keys={10,12,20};
vector<int> freq={34,8,50};
const int n=3;

int optimise_BST(int s,int e,int lvl,vector<vector<vector<int>>> &dp)
{
    if(s==e)
        return dp[s][e][lvl]=lvl*freq[s];
    
    if(dp[s][e][lvl]!=-1)
        return dp[s][e][lvl];
    
    int cost=INT_MAX;
    for(int cut=s;cut<=e;cut++)
    {
        int left=(cut-1<s)?0:optimise_BST(s,cut-1, lvl+1,dp);
        int right=(cut+1>e)?0:optimise_BST(cut+1, e, lvl+1,dp);
        
        cost=min(cost,left + lvl*freq[cut] + right);
    }
    return dp[s][e][lvl]=cost;
}

int main()
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
    cout<<optimise_BST(0,2,1,dp)<<endl;
}
