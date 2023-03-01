
// Prims algorithm implementation using priorty queue!
// Sumit Sir Method !!!

#include<iostream>
#include<queue>
using namespace std;

const int n=5;
vector<vector<pair<int,int>>> g(n);

void add_edge(int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

void prims()
{
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,-1,0});
    vector<bool> vis(n,false);
    
    while(!pq.empty())
    {
        vector<int> curr=pq.top();pq.pop();
        int s=curr[1],d=curr[2],cost=curr[0];
        
        if(vis[d]) continue;vis[d]=true;
        if(s!=-1) cout<<s<<"->"<<d<<"@"<<cost<<endl;
        for(auto e:g[d])
        {
            if(!vis[e.first])
                pq.push({e.second,d,e.first});
        }
    }
    
    cout<<"printed MST"<<endl;
}



int main()
{
    add_edge(0,1,2);
    add_edge(0,2,8);
    add_edge(1,2,3);
    add_edge(1,3,2);             //    add_edge(1,3,6); , for different spanning tree !
    add_edge(2,3,3);
    add_edge(2,4,1);
    add_edge(3,4,1);

    prims();
    
}
