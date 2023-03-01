

// To implement Khan's Algorithm for Topological Sort

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int n=6;
vector<vector<int>> graph(n,vector<int> ());

void addEdge(int u ,int v){
    graph[u].push_back(v);
}
    
void topo_khans_algo(){
    
    queue <int> q,ans;
    vector<int> indegree(n,0);
       
    for(int i=0;i<n;i++){
        for(int v:graph[i]){
            indegree[v]++;
        }
    }                               // or simply calculate indegree by indegree[i]=graph[i].size() , obviously for an undirected graph !!!
    
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        
        int top=q.front();
        q.pop();
        ans.push(top);

        for(int v:graph[top])               // here we do the decrement and checking at this step only because we just need to just in the updated neighbours only !
            if(--indegree[v]==0)                    // this is called smart coding brother !
                q.push(v);
        
    }
        
    
    if(ans.size()==n){
        cout<<"\n topological sort is :  ";
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }
    else
        cout<<"\n topological sort is not possible ";

}

int main(){
    
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
        
    topo_khans_algo();
    
    
}

