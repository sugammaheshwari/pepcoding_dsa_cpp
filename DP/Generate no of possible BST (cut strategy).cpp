
// To generate no of possible Binary Search Trees between the values 1-n
// For example the no of possible BST from 1,2,3 are 5 BST

#include<iostream>
#include<vector>
using namespace std;

int trees_p(int start,int end)
{
    if(start==end)
        return 1;
    
    int ans=0;
    for(int cut=start;cut<=end;cut++)
    {
        int left=(cut-1<start)?1:trees_p(start,cut-1);
        int right=(cut+1>end)?1:trees_p(cut+1,end);
        
        ans+=left*right;
    }
    return ans;
}

// Different way of handling the base condition !!!

int trees_p_2(int start,int end)
{
    if(start>=end)
        return 1;
    
    int ans=0;
    for(int cut=start;cut<=end;cut++)
    {
        int left=trees_p(start,cut-1);
        int right=trees_p(cut+1,end);
        
        ans+=left*right;
    }
    return ans;
}

int main()
{
    cout<<trees_p(1,3);
}
