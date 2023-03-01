
// PEPCODING graph Creation With weights
// This is an UNDIRECTED GRAPH as we will be adding edges from both u->v and v->u along with the weight w
// to do directed graph follow the code saved from geeks or you can easily modify this for directed graph .

#include<iostream>
#include<vector>

using namespace std;


class edge{

public:
    
    int v=0;
    int w=0;
    
    edge(int v ,int w){
        this->v=v;
        this->w=w;
    }
};


const int n=9;                        // n=9 for graph with 9 nodes
vector<edge *> graph[n];

void addEdge(int u,int v,int w){
    
    graph[u].push_back(new edge(v,w));
    graph[v].push_back(new edge(u,w));          // this second statement is to make edghe form v->u ,because we are making undirected graph
                                                // delete this to make directed graph , easy peasy !
}

void display(){
    
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(edge * e:graph[i]){
            cout<<"("<<e->v<<","<<e->w<<")"<<"\t";
        }
        cout<<endl;
    }
}

bool search_vertex(int u,int v){                // the objective of this function is to seach and return if a vertex 'v' is reachable from a given vertex 'u', it return T/F
    
    for(edge *e:graph[u]){
        if(e->v==v)
            return true;
    }
    return false;
}

int search_vertex_idx(int u,int v){         // this function does the same except returns index at which the vertex was found !
    
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i]->v==v)
            return i;
    }
    
    return -1;
}



void createGraph()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    // addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

    addEdge(7, 8, 3);
    // addEdge(2, 7, 3);
    // addEdge(2, 8, 3);

    // display();
    // removeEdge(3, 2);
    // removeVertex(3);

    display();
}

void solve()
{
    createGraph();
    
    cout<<"Found/NotFound:"<<search_vertex(3,7);
   // vector<bool> vis(n, false);
    // cout << hasPath(0, 6, vis, "") << endl;
    // cout << allPath(0, 6, vis, "") << endl;
    // BFS(0, vis);

   // GCC();
}

int main()
{
    solve();
    return 0;
}
