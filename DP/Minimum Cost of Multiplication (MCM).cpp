
// Matrix Chain Multiplication (MCM PROBLEM !!!)

/*
 Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
 
 (ABC)D = (AB)(CD) = A(BCD) = ....
 For example :
 
 (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
 A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
 
 */

#include<iostream>
#include<vector>
using namespace std;

int MCM(int sidx,int eidx,vector<int> &cost,vector<vector<int>> &dp)
{
    if(sidx+1==eidx)
        return dp[sidx][eidx]=0;
    
    if(dp[sidx][eidx]!=-1)
        return dp[sidx][eidx];
    
    int c=INT_MAX;
    
    for(int i=sidx+1;i<=eidx-1;i++)
    {
        int c1=MCM(sidx,i,cost,dp);
        int c2=MCM(i,eidx,cost,dp);
        int c_=cost[sidx]*cost[i]*cost[eidx];
        c=min(c,c1+c2+c_);
    }
       
    return dp[sidx][eidx]=c;
}

int MCM_tab(vector<int> &cost)
{
    return 0;
}

int MCM_tab(vector<int> &cost,int n,vector<vector<int>> &dp)
{
    for(int gap=1;gap<n;gap++)
    {
        for(int sidx=0,eidx=gap;eidx<n;eidx++,sidx++)
        {
            if(sidx+1==eidx)
            {
                dp[sidx][eidx]=0;
                continue;
            }

            int c=INT_MAX;
            
            for(int i=sidx+1;i<=eidx-1;i++)
            {
                int c1=dp[sidx][i];
                int c2=dp[i][eidx];
                int c_=cost[sidx]*cost[i]*cost[eidx];
                c=min(c,c1+c2+c_);
            }
               
            dp[sidx][eidx]=c;
        }
    }
    
    return dp[0][n-1];
}

int MCM_02(int sidx,int eidx,vector<int> &cost,vector<vector<int>> &dp,vector<vector<string>> &dps)
{
    if(sidx+1==eidx)
    {
        dps[sidx][eidx]=char('A'+sidx);
         return dp[sidx][eidx]=0;
    }
       
    
    if(dp[sidx][eidx]!=-1)
        return dp[sidx][eidx];
    
    int c=INT_MAX;
    string c_s="";
    
    for(int i=sidx+1;i<=eidx-1;i++)
    {
        int c1=MCM_02(sidx,i,cost,dp,dps);
        int c2=MCM_02(i,eidx,cost,dp,dps);
        int c_=cost[sidx]*cost[i]*cost[eidx];
        
        if(c>c1+c2+c_)
        {
            c=c1+c2+c_;
            c_s='('+dps[sidx][i]+dps[i][eidx]+')';
        }
    }
       
    dps[sidx][eidx]=c_s;
    return dp[sidx][eidx]=c;
}



void run_MCM_tab()
{
    vector<int> cost={1, 2, 3, 4};
    int n=int(cost.size());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<MCM_tab(cost,n,dp)<<endl;
    
    for(auto x:dp)
    {
        for(auto c:x)
            cout<<c<<":";
        cout<<endl;
    }
}

void run_MCM_02()
{
    vector<int> cost={10, 20, 30, 40, 30};
    int n=int(cost.size());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    vector<vector<string>> dps(n,vector<string>(n,"#"));
    cout<<MCM_02(0,n-1,cost,dp,dps)<<endl;
    
    for(auto x:dp)
    {
        for(auto y:x)
        {
            cout<<y<<":";
        }
        cout<<endl;
    }
    cout<<"the string dp formed is :"<<endl;
    
    for(auto x:dps)
    {
        for(auto y:x)
        {
            cout<<y<<"\t";
        }
        cout<<endl;
    }
    
}


void run_MCM()
{
    vector<int> cost={10, 20, 30, 40, 30};
    int n=int(cost.size());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<MCM(0,n-1,cost,dp)<<endl;
    
    for(auto x:dp)
    {
        for(auto y:x)
        {
            cout<<y<<":";
        }
        cout<<endl;
    }
}

int main()
{
    run_MCM_02();
    
}
