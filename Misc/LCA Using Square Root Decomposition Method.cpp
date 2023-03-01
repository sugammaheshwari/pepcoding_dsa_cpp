
// LCA using square root decomposition method !

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int n=10;
int max_depth=0;
vector<vector<int>> g(n);
vector<int> parent(n),depth(n),block_parent(n);
int bs=sqrt(max_depth)+1;
// expected input is required to be a graph sorted ie 0 -> 1,2,3,4,5 ; 1->6,7,8,9 children etc


void dfs1(int src,int lvl,int par)
{
    depth[src]=lvl;
    parent[src]=par;
    max_depth=max(max_depth,lvl);
    
    for(auto c:g[src])
        dfs1(c,lvl+1,src);
}

void dfs2(int src,int par)
{
    int d_src=depth[src];
    int d_par=depth[par];
    
    if(d_src/bs==d_par/bs)
        block_parent[src]=block_parent[par];
    else
        block_parent[src]=par;
    
    for(auto c:g[src])
        dfs2(c,src);
}


int LCA(int u,int v)
{
    while(block_parent[u]!=block_parent[v])
    {
        if(depth[u]>depth[v])
            swap(u,v);
        v=block_parent[v];                              // note here if we did v=parent[v], then it would be still correct BUTTTTT
    }                                                // fir square root decomposition ka kya hi use kiya bruh !
                                            // super imp thing !!!
    while(u!=v)
    {
        if(depth[u]>depth[v])
            swap(u, v);
        v=parent[v];
    }
    
    return u;                           // becuase LCA which we want finally converges to u=v;
}

int main()
{
    
    // NOTE: we need to initialise the graph , for now its uninitialised !
    
    dfs1(0,0,-1);               // -1 is the dummy node (or the dummy parent
    dfs2(0,-1);
    int u,v;
    cin>>u>>v;
    cout<<LCA(u,v);
}

