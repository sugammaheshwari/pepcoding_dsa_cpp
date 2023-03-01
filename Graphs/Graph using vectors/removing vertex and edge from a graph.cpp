
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

int search_vertex_idx(int u,int v){         // this function does the same except returns index at which the vertex was found !
    
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i]->v==v)
            return i;
    }
    
    return -1;
}

void remove_edge(int u,int v){            // removing a edge requires removal of forward and backward edge as demonstrated below !
    
    int Vidx=search_vertex_idx(u,v);
    int Uidx=search_vertex_idx(v,u);
    
    if(Vidx!=-1)                        // if condition could have also checkd Uidx!=-1 , redudant since ... you knoe ( if -1 element not found )
    {
        graph[u].erase(graph[u].begin()+Vidx);              // first time i am using built in function to remove element from vector using an index , good time saver!
        graph[v].erase(graph[v].begin()+Uidx);
    }
    
}


void removeVertex(int u)                                        //beautiful function YOLO!
{
    for (int i = int(graph[u].size()) - 1; i >= 0; i--)
    {
        int v = graph[u][i]->v;
        remove_edge(u, v);                      // this remove_edge function w/c we made earlier does the wonderfull work by deleting both forward and backward link!
    }
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
    // remove_edge(3, 2);
    removeVertex(3);

    display();
}

void solve()
{
    createGraph();
    
  //  cout<<"Found/NotFound:"<<search_vertex_idx(3,7);
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
