
// To implement Insertion Sort Algorithm
// Easy Sorting Algorithm with Run time complexity of O(N^2).

#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &v)
{
    int n=(int)v.size();
    
    for(int i=1;i<n;i++)
    {
        int curr=v[i];
        
        int j=i-1;
        while(j>=0 && v[j]>curr)
        {
            v[j+1]=v[j];
            j--;
        }
        v[++j]=curr;
    }
    return;
}

int main()
{
    vector<int> v={1,7,34,723,177,134,71381,671,-35,137341,1,413,-1,125,-1291,1912,0,24};
    insertion_sort(v);
    
    for(auto x:v)
        cout<<x<<" ";
}
