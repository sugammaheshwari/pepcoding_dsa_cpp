

//  program to find if a graph has path from source to destination !

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

int find_index(int u,int v){
    
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i]->v==v)
            return i;
    }
    
    return -1;
    
}

 // when i was designing this code i thought whats the use of visited , since the graph is non directional thus it contains cycles , so the code without visited will be an infinite recursive call
// thus we use visited !

bool has_path(int src,int des,vector<bool> &vis,string ans){
    
    if(src==des){
        cout<<endl<<ans<<" "<<des<<endl;
        return true;
    }
    
    vis[src]=true;
    bool res=false;
    
    for(int i=0;i<graph[src].size();i++){
        if(!vis[graph[src][i]->v])
            res = res || has_path( graph[src][i]->v, des, vis, ans + to_string(src) + " ") ;
    }
    
    return res;
}

// below is code for calculating and displaying all the possible paths
// in the for loop here the looping technique used is different
// variety is the spice of life !

int allPath_count_n_display(int src, int desti, vector<bool> &vis, string ans)
{

    if (src == desti)
    {
        cout << ans + to_string(desti) << endl;
        return 1;
    }
    vis[src] = true;

    int count = 0;
    for (edge *e : graph[src])
    {
        if (!vis[e->v])
            count += allPath_count_n_display(e->v, desti, vis, ans + to_string(src) + " ");
    }

    vis[src] = false;

    return count;
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
    //removeVertex(3);

    vector<bool> vis(n,false);
    cout<<endl<<allPath_count_n_display(1,3,vis,"")<<endl;
    
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
