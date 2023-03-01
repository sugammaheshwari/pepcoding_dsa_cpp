
/*
 
 BOX STACKING PROBLEM
 Geeks :  https://practice.geeksforgeeks.org/problems/box-stacking/1
 
 Description : You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.
 
  METHOD 1  : using recurrsion ( With DP )
  METHOD 2: using Modified Longest common Subsequence Technique !!! ( Tabularization Method )
 
 
 */


#include<iostream>
#include<vector>
#include<map>
using namespace std;


int BOX_stacking_tab()
{
    // gets input from the user of no of boxes and their dimension respectively
    int n;
    cin>>n;
    vector<vector<int>> dimensions(n,vector<int>(3));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>dimensions[i][j];
    
    vector<vector<int>> d2;
    
    // please note here the condition in for loop is for inserting in d2 in the order x1>x2
    // i have tried without this and the tabularization code fails to submit on geeks
    // obviously recurssion method main it doesnt matter if we insert in this order or not becuse we are trying all the possiblities
    // but in tab method since it builds on LIS this step is critical
    // Cheers !!!
    
    for(auto x:dimensions)
    {
        if(x[0]>x[1])
            d2.push_back({x[0],x[1],x[2]});
        else
            d2.push_back({x[1],x[0],x[2]});
        if(x[1]>x[2])
            d2.push_back({x[1],x[2],x[0]});
        else
            d2.push_back({x[2],x[1],x[0]});
        if(x[2]>x[0])
            d2.push_back({x[2],x[0],x[1]});
        else
            d2.push_back({x[0],x[2],x[1]});
    }
    
    sort(d2.begin(),d2.end(),[](vector<int> &d1,vector<int> &d2)                // sorted in decreasing order on basis of area
         {
            if(d1[0]*d1[1]>d2[0]*d2[1])
                return d1>d2;
        return d1[0]>d2[0];                                                 // .. if area is same then sorted on basis of first element !
        });
    
    
    vector<int> dp(d2.size());
    
    for(int i=0;i<d2.size();i++)                                // initialising
        dp[i]=d2[i][2];
    
    int g_max=dp[d2.size()-1];
    for(int i=int(d2.size())-2;i>=0;i--)                                 // regular LIS Technique
    {
        int l_add=0;
        for(int j=i+1;j<int(d2.size());j++)
        {
            if( (d2[j][0]<d2[i][0] && d2[j][1]<d2[i][1]) || (d2[j][1]<d2[i][0] && d2[j][0]<d2[i][1]) )
                l_add=max(l_add,dp[j]);
        }
        
        dp[i]+=l_add;
        g_max=max(g_max,dp[i]);
    }
    return g_max;
}





int main()
{
   cout<<endl<< BOX_stacking_tab();
   
    
    
}






int arrange(vector<vector<int>> &d,int idx,int l,int b,map<vector<int>,int> &dp)
{
    if(idx==d.size())
        return dp[{idx,l,b}]=0;
    
    if(dp[{idx,l,b}]!=0)
        return dp[{idx,l,b}];

    int ans=0;
    
    for(int i=idx;i<d.size();i++)
    {
        if( d[i][0]<l && d[i][1]<b )
           ans=max(ans,d[i][2]+arrange(d,idx+1,d[i][0],d[i][1],dp));
        if( d[i][1]<l && d[i][0]<b )
           ans=max(ans,d[i][2]+arrange(d,idx+1,d[i][1],d[i][0],dp));
    }
    
    return dp[{idx,l,b}]=ans;
}



void BOX_STACKING_main()
{
    // gets input from the user of no of boxes and their dimension respectively
    int n;
    cin>>n;
    vector<vector<int>> dimensions(n,vector<int>(3));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>dimensions[i][j];
    
    vector<vector<int>> d2;
    
    for(auto x:dimensions)
    {
        d2.push_back({x[0],x[1],x[2]});
        d2.push_back({x[1],x[2],x[0]});
        d2.push_back({x[2],x[0],x[1]});
    }
    
    
    sort(d2.begin(),d2.end(),[](vector<int> &d1,vector<int> &d2)
         {
            if(d1[0]*d1[1]>d2[0]*d2[1])
                return d1>d2;
        return d1[0]>d2[0];
        });
    
    map<vector<int>,int> dp;
    cout<<"the max height after stacking is :"<<arrange(d2,0,INT_MAX,INT_MAX,dp);
}
