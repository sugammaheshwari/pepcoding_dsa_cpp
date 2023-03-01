
/*
 
                Topological Sorting
 [Topological sorting for Directed Acyclic Graph (DAG) ]

 The below method is from geeksforgeek it uses adjacency list to implement graph
 The Topological sort is implemented using DFS alogithm and by adding elements to stack in post area of recursion ! ( in topo_Sort_util function
 
 This code cant handle cycles thus comes in the role khan's alogorithm which helps to combat this problem !
 
 link : https://www.geeksforgeeks.org/topological-sorting/
 
 */


#include<iostream>
#include<stack>
#include<list>
using namespace std;


class Graph{
    
    int V;
    list <int> *adj;
    
    void topo_sort_util(int v,bool visited[],stack <int> &Stack);           // utility function through which we do recursion and store result in passed stack !
    
public:
    
    Graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }
    
    void addEdge(int u,int v);
    void topo_sort();
    
};


void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::topo_sort_util(int v,bool visited[],stack <int> &Stack){
    
    visited[v]=true;
    
    list<int> ::iterator itr;
    
    for(itr=adj[v].begin();itr!=adj[v].end();itr++){
        if(!visited[*itr])
            topo_sort_util(*itr, visited, Stack);
    }
    
    Stack.push(v);
    
}

void Graph::topo_sort(){
    
    stack<int> Stack;
    bool vis[V];
    
    for(int i=0;i<V;i++){
        vis[i]=false;
    }
    
    for(int i=0;i<V;i++){
        if(!vis[i])
            topo_sort_util(i,vis, Stack);
    }
    
    // finally just need to print the stack we made using the recursive function( topo_sort_util ) and the for loop
    
    while(!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    
}




int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
  
    cout << "Following is a Topological Sort of the given graph \n";
    g.topo_sort();
  
    return 0;
}
