
// Tabularization method for permuation and combination problems !!!


#include<iostream>
#include<vector>
using namespace std;
 
int permutation(vector<int> &coins,int t)
{
    vector<int> dp(t+1,0);
    dp[0]=1;
    
    for(int i=1;i<=t;i++)
    {
        for(auto x:coins)
            if(i-x>=0)
                dp[i]+=dp[i-x];
    }
    
    for(auto x:dp)
        cout<<x<<":";
    
    cout<<endl;
    return dp[t];
}

int combination(vector<int> &coins,int t)
{
    vector<int> dp(t+1,0);
    dp[0]=1;
    
    for(auto x:coins)
    {
        for(int i=1;i<=t;i++)
        {
            if(i-x>=0)
                dp[i]+=dp[i-x];
        }
    }
    
    for(auto c:dp)
        cout<<c<<":";
    cout<<endl;
    return dp[t];
}

// Q2:Find number of solutions of a linear equation of n variables
/* link:https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/

    here we can directly solve this question by using coefficients of variables as coins and target as the rhs of the equation.
 
   ans = combination(coefficients,RHS)
 
 */

int main()
{
    vector<int> coins={2,3,5,7};
    cout<<endl<<combination(coins,8)<<endl;
}
