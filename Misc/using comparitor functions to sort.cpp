
#include<iostream>
#include<vector>
using namespace std;

bool comp(vector<int> x1,vector<int> x2)
{
    if(x1[0]==x2[0])
        return x1[1]>x2[1];
    else
        return x1[0]<x2[0];
}


int main()
{
    vector<vector<int>> arr={{5,4},{6,4},{6,7},{2,3}};
    sort(arr.begin(),arr.end(),comp);
    
    for(auto x:arr)
    {
        cout<<x[0]<<":"<<x[1]<<endl;
    }
    return 1;
    
}
