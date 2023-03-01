

// Pepcoding BFS of an undirected graph

#include<iostream>
#include<vector>
#include<queue>

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

void BFS(int src,vector<bool> &vis){
    
    queue<int> q;
    q.push(src);
    vis[src]=true;
    
    while(!q.empty()){
        
        int top=q.front();
        cout<<endl<<"vertex:"<<top;
        q.pop();
        
        for(edge *e:graph[top]){
            if(vis[e->v]==false){
                q.push(e->v);
                vis[e->v]=true;
            }
        }
        
    }

}


void createGraph()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
     addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

    addEdge(7, 8, 3);

    display();
}

void solve()
{
    createGraph();
    vector<bool> vis(n,false);
    BFS(0,vis);
}

int main()
{
    solve();
    return 0;
}
