
// GOLD MINE solution problem using DP !
// link : https://www.geeksforgeeks.org/gold-mine-problem/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mat =   {{1, 3, 3},
                            {2, 1, 4},
                            {0, 6, 4}};

int m=3;
int n=3;

// MEMOIZATION SOLUTION

int collect_gold(int sr,int sc,int m,int n,int gold,vector<vector<int>> &dp)
{
    if(sc==n)
        return dp[sr][sc];
    
    if(dp[sr][sc]!=0)
        return dp[sr][sc];
    
    int p1=0,p2=0,p3=0;
    
    if(sr+1<m && sc+1<n)
        p1=collect_gold(sr+1,sc+1,m,n,gold+mat[sr][sc],dp);
    if(sr-1>=0 && sc+1<n)
        p2=collect_gold(sr-1,sc+1,m,n,gold+mat[sr][sc],dp);
    if(sc+1<m)
        p3=collect_gold(sr,sc+1,m,n,gold+mat[sr][sc],dp);
        
    return dp[sr][sc]=(max(max(p1,p2),p3)+mat[sr][sc]);
}

//   USING TABULATION METHOD !

int collect_gold_DP(int m,int n,vector<vector<int>> &dp)
{
    for(int j=n-1;j>=0;j--)
    {
        for(int i=m-1;i>=0;i--)
        {
            if(j==n-1)
            {
                dp[i][j]=mat[i][j];
                continue;
            }
            
            int p1=0,p2=0,p3=0;
            if(i+1<m && j+1<n)
                p1=dp[i+1][j+1];
            if(i-1>=0 && j+1<n)
                p2=dp[i-1][j+1];
            if(j+1<n)
                p3=dp[i][j+1];
            
            dp[i][j]= max(max(p1,p2),p3) + mat[i][j];
        }
    }
    
    int max_gold=0;
    
    for(int i=0;i<m;i++)
        max_gold=max(max_gold,dp[i][0]);
    
        return max_gold;
}


int main(){
    
    vector<vector<int>> dp(m,vector<int>(n,0));
    
    //decomment to run first code , for memoization version !
    
//    int gold=0;
//    for(int i=0;i<m;i++)
//        dp[i][n]=mat[i][n];
//
//    for(int i=0;i<m;i++)
//        gold=max(gold,collect_gold(i,0,m,n,0,dp));
//
//    cout<<"max amount that can be collected is :"<<gold<<endl;
//
//    for(auto x:dp)
//    {
//        for(auto y:x)
//            cout<<y<<":";
//        cout<<endl;
//    }

    
    // code for DP version !
    
    
    cout<<endl<<"The Amount of maximum Gold that can be Collected is :"<<collect_gold_DP(m,n,dp)<<endl;


        for(auto x:dp)
        {
            for(auto y:x)
                cout<<y<<":";
            cout<<endl;
        }

}
