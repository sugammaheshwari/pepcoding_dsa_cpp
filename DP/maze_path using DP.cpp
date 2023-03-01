

#include<iostream>
#include<vector>
using namespace std;

int maze_path(int sr,int sc,int er,int ec,vector<vector<int>> &dp)
{
    if(sr==er && sc==ec)
    {
        dp[er][ec]=1;
        return 1;
    }
    
    if(dp[sr][sc]!=0)
        return dp[sr][sc];
        
    int count=0;
    
    if(sr+1<=er)
        count+=maze_path(sr+1,sc,er,ec,dp);
    
    if(sc+1<=ec)
        count+=maze_path(sr,sc+1,er,ec,dp);
    
    if(sr+1<=er && sc+1<=ec)
        count+=maze_path(sr+1,sc+1,er,ec,dp);
    
    dp[sr][sc]=count;
    return count;
}

void display_2D(vector<vector<int>> &v)
{
    for(auto x:v)
    {
        for(auto y:x)
            cout<<y<<":";
        cout<<endl;
    }
    
}

int main()
{
    int sr=0,sc=0,er=2,ec=2;
    vector<vector<int>> dp(er+1,vector<int>(ec+1,0));
    cout<<"the no of paths are::"<<maze_path(sr,sc,er,ec,dp)<<endl;
    
    // dp grid formed can be Displayed as follows!
    display_2D(dp);
}
