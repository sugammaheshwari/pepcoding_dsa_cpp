
/*
 
 DIJKTRAS ALGORITHM
 Video Explanation: https://www.youtube.com/watch?v=7GoDDj3onfI
 
 its implementation is a lot similar to prims algorithm
 i will draw to the differnce in working of both the algorithms !
 in prims algo we were finding the minimum spanning tree of the graph and our abstract data structure vertex_data
 was storing the list of edges which will be included in the MST
 
 in Dijktras Algorihtm we try to find the minium cost from a source vectex to all the vertex
 
 */

#include<iostream>
#include<vector>
using namespace std;

const int n=9;
vector<vector<pair<int,int>>> g(n);

void add_edge(int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

int find_min_idx(vector<int> &cost,vector<bool> &un_vis)
{
    int t=INT_MAX;int idx=-1;
    for(int i=0;i<cost.size();i++)
    {
        if(un_vis[i] && cost[i]<t)
        {
            t=cost[i];
            idx=i;
        }
    }
    return idx;
}

vector<int> cost_From_source(n,INT_MAX);

void Dijktras_algo(int s)
{
    vector<bool> vis(n,false);
    vector<bool> un_vis(n,true);
    cost_From_source[s]=0;
    int count=0;
    
    while(count<n)
    {
        int min_idx=find_min_idx(cost_From_source,un_vis);
        vis[min_idx]=true; un_vis[min_idx]=false;
        
        for(auto x:g[min_idx])
        {
            int i=x.first;int w=x.second;
            if(un_vis[i] && cost_From_source[i]>(w+cost_From_source[min_idx]) )
                cost_From_source[i]=cost_From_source[min_idx]+w;
        }
        
        count++;
    }
}


int main()
{
    
    // example graph taken from geeks_for_geeks @ https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    
    add_edge(0,1,4);
    add_edge(0,7,8);
    add_edge(1,7,11);
    add_edge(1,2,8);
    add_edge(7,8,7);
    add_edge(7,6,1);
    add_edge(2,8,2);
    add_edge(6,8,6);
    add_edge(6,5,2);
    add_edge(5,2,14);
    add_edge(3,2,7);
    add_edge(3,5,14);
    add_edge(4,5,10);
    add_edge(3,4,9);

    Dijktras_algo(0);
    
    for(int i=0;i<n;i++)
    {
        cout<<"the resp min. cost for each vertex is :"<<i<<":"<<cost_From_source[i]<<endl;
    }
    
}
