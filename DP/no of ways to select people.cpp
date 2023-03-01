
/*
 Q:No of Ways to Pair People question if a person can either be in a pair or single by himself !
 Given that there are p people in a party. Each person can either join dance as a single individual or as a pair with any other. The task is to find the number of different ways in which p people can join the dance.
 
 Input : p = 3
 Output : 4
 Let the three people be P1, P2 and P3
 Different ways are: {P1, P2, P3}, {{P1, P2}, P3},
 {{P1, P3}, P2} and {{P2, P3}, P1}.
 
 
 https://www.geeksforgeeks.org/number-of-ways-to-pair-people/
 */


#include<iostream>
#include<vector>
using namespace std;


//recurssion !
int find_ways(int p)
{
    if(p<=1)
        return 1;
    // * this base case represent that all have been paired up
    // thus returning 1!
    
    return (find_ways(p-1) + (p-1)*find_ways(p-2));
}

//memoization

int find_ways(int p,vector<int> &dp)
{
    if(p<=1)
        return dp[p]=1;
    
    return dp[p]=find_ways(p-1) + (p-1)*find_ways(p-2) ;
}

//Tabularization Method !

int find_ways_DP(int p,vector<int> &dp)
{
    for(int i=1;i<=p;i++)
    {
        if(i<=1)
        {
            dp[i]=1;
            continue;
        }
        
        dp[i]= dp[i-1] + (i-1)*dp[i-2] ;
    }
    return dp[p];
}


int main(){
    
    vector<int> dp(5,0);
    cout<<find_ways_DP(, dp);
}


