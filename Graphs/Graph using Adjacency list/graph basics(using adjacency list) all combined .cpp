

// for Acyclic Graph
// for cyclic graph khan's algorithm is used , refer to code for that !
// and here i have made DFS,BFS,Topo_sort from an index which is passed as an argument
// code differs as per the use case !

#include<iostream>
#include<list>
#include<queue>
#include<stack>

using namespace std;

class graph{
    
    int V;
    list <int> *adj;

public:
    
    graph(int v){
        
        this->V=v;
        this->adj=new list<int>[v];
    }
    
    void add_edge(int u,int v){
        adj[u].push_back(v);
    }
    
    void BFS(int s);
    
    void DFS(int s);
    void DFS_util(int s,vector<bool> &vis);
    
    void DFS_for_topo(int s);
    void DFS_util_for_topo(int s,vector<bool> &vis,stack<int> &st);
    
    void display_graph();

};


void graph::BFS(int s){
    
    queue<int> q;
    vector<bool> vis(V,false);
    
    q.push(s);
    
    
    while(!q.empty()){
        
        int vertex=q.front();
        cout<<vertex<<" ";

        q.pop();
        
        list <int> ::iterator itr;
        
        if(!vis[vertex]){
            for(itr=adj[vertex].begin();itr!=adj[vertex].end();itr++){
                if(!vis[*itr])
                    q.push(*itr);
            }
        }
        
        vis[vertex]=true;
    }
    
}

void graph::DFS(int s){
    
    vector<bool> vis(V,false);
    DFS_util(s,vis);
    
}

void graph::DFS_util(int s,vector<bool> &vis){
    
    cout<<s<<" ";
    vis[s]=true;
    
    list <int> :: iterator i;
    
    for(i=adj[s].begin();i!=adj[s].end();i++){
        if(vis[*i]==false){
            DFS_util(*i,vis);
        }
    }
}


void graph::DFS_for_topo(int s){
    
    vector<bool> vis(V,false);
    stack <int> st;
   
    for(int i=0;i<V;i++){
           if(!vis[i])
               DFS_util_for_topo(s,vis,st);
       }

    cout<<endl<<"The topological sort is:";
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
}

void graph::DFS_util_for_topo(int s,vector<bool> &vis,stack<int> &st){
    
   
    vis[s]=true;
    
    list <int> :: iterator i;
    
    for(i=adj[s].begin();i!=adj[s].end();i++){
        if(vis[*i]==false){
            DFS_util_for_topo(*i,vis,st);
        }
    }
    
    st.push(s);
    
}



void graph::display_graph(){
    
    list<int> :: iterator itr;
    
    for(int i=0;i<V;i++){
        cout<<"vertex:  "<<i<<"edges:  ";
        for(itr=adj[i].begin();itr!=adj[i].end();itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    
}


int main(){
    
    graph g(7);
    g.add_edge(0, 1);
    g.add_edge(0, 6);
    g.add_edge(1, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 2);
    g.add_edge(5,6);
    g.add_edge(4,5);
    
    cout<<"the graph is :"<<endl;
    g.display_graph();
    cout<<"the BFS is :"<<endl;
    g.BFS(0);
    cout<<endl;
    cout<<"the DFS is :"<<endl;
    g.DFS(0);
    cout<<endl;
    g.DFS_for_topo(0);
    
}
