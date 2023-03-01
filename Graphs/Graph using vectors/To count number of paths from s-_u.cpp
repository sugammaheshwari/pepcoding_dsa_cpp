#include<iostream>
#include<vector>
using namespace std;

const int n=5;
vector<vector<int>> g(n,vector<int>());

void addEdge(int u,int v){
    g[u].push_back(v);
}

int c_=0;

int dfs_util(int s,int f,vector<bool> &vis){
    
    if(s==f){
        return 1;
    }
    
    vis[s]=true;
    int c=0;
    
    for(int u:g[s]){
        if(!vis[u])
            c+=dfs_util(u,f,vis);
    }
    
    vis[s]=false;
    
    return c;
}

void DFS(int s,int f,vector<bool> &vis){
    
    vis[s]=true;
    for(int u:g[s]){
        c_+=dfs_util(u,f,vis);
    }
    
    cout<<endl<<"the no of paths are :"<<c_;
}


int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(2, 0);
    addEdge(2, 1);
    addEdge(1, 3);
  
    vector<bool> vis(n,false);

    DFS(2,3,vis);cout<<endl;
    
    return 0;
}
