
// To find the kth permutation Sequence with the given n
// link : https://leetcode.com/problems/permutation-sequence/submissions/

#include<iostream>
#include<vector>
using namespace std;

string g_ans;

int fact(int n)
{
    if(n<=1)
        return 1;
    return fact(n-1)*n;
}

void perm(int n,int k,vector<bool> &vis,string ans)
{
    if(k==1)
    {
        for(int i=0;i<vis.size();i++)
            if(!vis[i])
                ans+=to_string(i);
        g_ans=ans;
        return;
    }
    
    int f=fact(n-1),count=0;
    while(k-f>=1)
    {
        count++;
        k-=f;
    }
    
    int idx=1;
    while(count!=0) if(!vis[idx++]) count--;
    while(vis[idx]) idx++;

    vis[idx]=true;
    perm(n-1,k,vis,ans+to_string(idx));
}




int main()
{
    g_ans="";
    int n=3,k=3;
    vector<bool> vis(n+1,false);
    vis[0]=true;
    perm(n,k,vis,"");
    cout<<g_ans<<endl;
}
