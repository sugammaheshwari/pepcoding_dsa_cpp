
// Dijktras' algorithm implementation using priorty queue!
// Sumit Sir Method !!!

#include<iostream>
#include<queue>
using namespace std;

int n=9;
vector<vector<pair<int,int>>> g(n);

void addEdge(int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

void set_graph()
{
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
}

void Dijktras(int src)
{
    vector<bool> vis(n,false);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,-1,src});
    
    while(!pq.empty())
    {
        vector<int> curr=pq.top();pq.pop();
        int dis=curr[0],s=curr[1],d=curr[2];
        if(vis[d]) continue;
        cout<<d<<":"<<dis<<endl;vis[d]=true;
        
        for(auto e:g[d])
        {
            if(!vis[e.first])
                pq.push({dis+e.second,d,e.first});
        }
    }
    
    cout<<"finished running diktras'"<<endl;
}



int main()
{
    set_graph();
    Dijktras(0);
}
