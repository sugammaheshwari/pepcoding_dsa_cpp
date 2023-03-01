
// 0/1 Knapsack Problem Solution using Dynamic Programming !

#include<iostream>
#include<vector>
using namespace std;

vector<int> weights={10,20,30};
vector<int> values={60,100,120};
vector<pair<float,int>> V_W;

// Method 1: for solving knapsack problem by sorting the pairs by V/W ratio and then choosing greedily !!
void knapsack(int idx,string ans,int target)
{
    if(target==0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=idx;i<V_W.size();i++)
    {
        if(target-weights[V_W[i].second]>=0)
            knapsack(idx+1,ans+"+"+to_string(values[V_W[i].second]),target-weights[V_W[i].second]);
    }
}

void run_knapsak()
{
    for(int i=0;i<weights.size();i++)
        V_W.push_back({values[i]/weights[i],i});
    
    sort(V_W.begin(),V_W.end(),greater<>());
    
    knapsack(0,"",50);
}

// Method 2: By taking the maximum at each recurssion call  ie : max(picking the weight , not picking the weight )

int knapsack_2(vector<int> &weights,vector<int> &values,int w,int idx)
{
    if(idx==weights.size() || w==0)
        return 0;
    
    if(dp[idx][w]!=0)
        return dp[idx][w];
    
    int picked_current_weight=0;
    if(w-weights[idx]>=0)
        picked_current_weight=knapsack_2(weights,values,w-weights[idx],idx+1,dp);
    
    int not_picked_current_weight=knapsack_2(weights,values,w,idx+1,dp);
    
    return max(picked_current_weight,not_picked_current_weight);

}

void run_knapsak_2()
{
    vector<vector<int>> dp(weights.size()+1,vector<int>(30+1));
    cout<<endl<<knapsack_2(weights,values,50,0,dp);
    
    for(auto x:dp)
    {
        for(auto c:x)
            cout<<c<<":";
        cout<<endl;
    }

}

int main()
{
    run_knapsak_2();
    
}
