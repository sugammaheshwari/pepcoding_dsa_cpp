

// program to find redundant connection using path DSU path compression and union technique !
// can also be used to detect cycle in a graph !!
// awesome video link for theory explanation : https://www.youtube.com/watch?v=wU6udHRIkcc&t=51s

#include<iostream>
#include<vector>

using namespace std;

const int n=3;
vector<vector<int>> graph(n,vector<int>());

vector<int> parent,size;

void add_edge(int u,int v){         // undirected graph adding edge in both the directions !
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int find_parent(int u){
    
    if(parent[u]==u){
        return u;
    }
    
    int p=find_parent(parent[u]);       // recursively finds the parent from the parent array , ie the top most parent
    
    parent[u]=p;            // this statement is used for compression , finding parent with most weight through recursive calls and in post area
                            // finally making the 'p' as the parent at 'u'th index , the index which made the call , beautiful technique !
    return p;
}
    
void merge(int p1,int p2){          // this function is the union of two sets , merges the smaller parent into bigger one by comparing thier size !
    
    if(size[p1]>size[p2]){
        parent[p2]=p1;
        size[p1]+=size[p2];
    }
    else{                   // ofcourse else case handles the case when p1 size equals to p2 size
        parent[p1]=p2;
        size[p2]+=size[p1];
    }
    
}

void  Return_detected_cycle_forming_edges(vector<vector<int>> &edges){
    
    // populating our size and parent vector as follows...
    
    for(int i=0;i<n;i++){
        parent.push_back(i);                       // making each vertex parent of itself
        size.push_back(1);                              // default size of each subset is 1;
    }
    
    for(vector<int> ed:edges){
            
        int p1=find_parent(ed[0]);                   // this finds the parents and returns while doing compression in post area !
        int p2=find_parent(ed[1]);
        
        if(p1!=p2){
            merge(p1,p2);
        }
        
        else{
            cout<<ed[0]<<":"<<ed[1]<<endl;              // Displaying the redundant connection !
        }
        
    }
}

void show_graph(){
    
    cout<<endl;

    for(int i=0;i<graph.size();i++){
        cout<<"vertex:"<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<",";
        }
        cout<<endl;
    }
    
    cout<<endl;
}


int main(){

    cout<<endl<<"the graph is :"<<endl;
    
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 2);
    
    show_graph();
    
    vector<vector<int>> edges {{0,1},{0,2},{1,2}};
    
    cout<<"the redundant connection is ";
    
    Return_detected_cycle_forming_edges(edges);
    
}
