
// To generate all the possible subsets of a given set !!!

#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> ans;
void find(vector<int> &n,int idx,vector<int> s)
{
    if(idx==n.size())
    {
        ans.push_back(s);
        return;
     }
    
    find(n,idx+1,s);
    s.push_back(n[idx]);
    find(n,idx+1,s);
}


int main()
{
    vector<int> x;
    vector<int> nums={1,5,8,23,2};
    find(nums,0,x);

    // display ans to show all the subsets !!!
        
}
