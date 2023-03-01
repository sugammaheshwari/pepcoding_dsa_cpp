
// Unbounded Knapsack (Repetition of items allowed)
/*
 Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.

 */

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vals={10, 40, 50, 70};
    vector<int> weights={1, 3, 4, 5};
    
    int limit=8;
    vector<int> dp(limit+1,0);
    
    for(int i=0;i<=limit;i++)
    {
        for(int j=0;j<weights.size();j++)
            if(i-weights[j]>=0)
                dp[i]=max(dp[i],dp[i-weights[j]]+vals[j]);
        
        // here we dont need to max with previous state answer dp[i]=max(dp[i],dp[i-1]) because the answer if being built one by one with first weight
        // and current state already has answer with previous weight from the previous iterations of the loop !
        
    }
    
    cout<<dp[limit]<<endl;
}
