
// Geeks : Merge Two non Decreasing array in place (ie without using extra memory !)
// Link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);                   // for faster input/output
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    for(int t=1;t<=T;t++)
    {
        int m,n;
        cin>>m>>n;
        int a1[m];
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<m;i++)
            cin>>a1[i];
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            pq.push(x);
        }
        
        int i=0;
        while(i<m && !pq.empty())
        {
            int top=pq.top();
            if(a1[i]>top)
            {
                int temp=a1[i];
                a1[i]=top;
                pq.pop();
                pq.push(temp);
            }
            i++;
        }
        
        for(auto x:a1)
            cout<<x<<" ";
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
    }
    return 0;
}
