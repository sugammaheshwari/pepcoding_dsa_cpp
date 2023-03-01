

#include<iostream>
#include<vector>
using namespace std;

int maze_path(int sr,int sc,int er,int ec,vector<vector<int>> &dp)
{
    for(int i=er;i>=0;i--)
    {
        for(int j=ec;j>=0;j--)
        {
            if(i==er && j==ec)
            {
                dp[i][j]=1;
                continue;
            }
            int count=0;
            if(i+1<=er)
                count+=dp[i+1][j];
            if(j+1<=ec)
                count+=dp[i][j+1];
            if(i+1<=er && j+1<=ec)
                count+=dp[i+1][j+1];
            
            dp[i][j]=count;
        }
    }
    return dp[0][0];
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
    maze_path(sr,sc,er,ec,dp);
    
    cout<<endl<<"the no of paths using tabulation DP method are:"<<dp[0][0]<<endl;
    
    cout<<" dp grid formed is as follows :"<<endl;
    display_2D(dp);
}
