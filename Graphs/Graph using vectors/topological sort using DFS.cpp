

// Directed Acyclic-Graph
// Pepcoding method , without using adjacency list
// uses vector of vector list ;

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

const int n=9;

vector<vector<int> > graph(n,vector<int>());

void add_edge(int u,int v)
{
    graph[u].push_back(v);
}

void display_graph(){
    
    for(int i=0;i<n;i++){
        cout<<"Vertex :"<<i<<" ";
        for(int v:graph[i])
            cout<<v<<" ";
    }
    cout<<endl;
    
}

void topo_dfs_util(int s,vector<bool> &vis,stack <int> &st){
    
    vis[s]=true;
    
    for(int v:graph[s])
        if(!vis[v])
            topo_dfs_util(v, vis, st);
    
    st.push(s);
}

void topological_sort(){
    
    vector<bool> vis(n,false);
    stack<int> st;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo_dfs_util(i,vis,st);
        }
    }
    
    cout<<"the topological sort is : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}

