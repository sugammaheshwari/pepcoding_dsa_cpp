
// DFS : Depth First Search in a graph : using adjacency list representation 
// Directed Graph

#include<iostream>
#include<list>          // list is a STL for doubly linked link-list
using namespace std;

class graph{
    
    int V;                       // no of vertices
    list <int> *adj ;               // adj= adj list for every single vertex.
    // its how it is used list <new> returns a pointer to the doubly link list , this is explation for the time being
    
    public:
    
    graph(int v);
    
    void DFS_util(int v,bool visited[]);        // a utility function to traverse the graph from the node to the maximum
                                            //depth possible and checking if the node is unvisited as a graph can contain cycles so
                                            //, we want to avoid repeated printing.
    
    void add_edge(int v, int w);
    
    void DFS(int v);

};


graph::graph(int v){

    this->V=v;              // constructor sets the value of V=no of vertices to V=passed value
    adj=new list<int>[V];       // thats why we added pointer in the list<int> *adj private member
}

void graph::add_edge(int v, int w){
    
    adj[v].push_back(w);            // we added w to v's list ,ie link list at vth position.
}


void graph::DFS_util(int v, bool visited[]){
    
    visited[v]=true;
    cout<<v<< " ";
    
    list<int> :: iterator itr;
    
    for(itr=adj[v].begin();itr!=adj[v].end();itr++)
        if(!visited[*itr])
            DFS_util(*itr, visited);
    
}

void graph::DFS(int v){
    
    bool *visited=new bool[V];               // alternate syntax : bool visited[V] works perfectly fine !
    for(int i=0;i<V;i++){                      // after declaration setting all the visited to false; , since this no vector we need to set all values false manually
        visited[i]=false;
    }
    
    DFS_util(v,visited);
    
}

int main(){
    graph g(4);
      g.add_edge(0, 1);
      g.add_edge(0, 2);
      g.add_edge(1, 2);
      g.add_edge(2, 0);
      g.add_edge(2, 3);
      g.add_edge(3, 3);
    
      cout << "Following is Depth First Traversal"
              " (starting from vertex 2) \n";
      g.DFS(2);
    
}
