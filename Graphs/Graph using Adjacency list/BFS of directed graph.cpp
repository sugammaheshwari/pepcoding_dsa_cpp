
// BFS Of a Directed Graph
//https://media.geeksforgeeks.org/wp-content/uploads/bfs-5.png

#include<iostream>
#include<list>
#include<queue>

using namespace std;

class graph{
    
    int V;
    list <int> *adj;

public:
    
    graph(int v){
        this->V=v;
        this->adj=new list<int>[V];
    }

    void BFS(int s);
    void add_edge(int v,int w);
    
};

void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void graph::BFS(int s){
    
    bool *visited=new bool[V];
    
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    
    queue<int> qu;
    
    visited[s]=true;
    qu.push(s);
    
    list<int>  ::iterator itr;
    
    while(!qu.empty()){
        
        s=qu.front();
        cout<<s<<" ";
        qu.pop();
        
        for(itr=adj[s].begin();itr!=adj[s].end();itr++){
            if(!visited[*itr]){
                visited[*itr]=true;
                qu.push(*itr);
            }
        }
    }
}


int main()
{
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
  
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
   
    g.BFS(2);
  
    return 0;
}
