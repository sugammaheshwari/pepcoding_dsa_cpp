
// TO CHECK CYCLE IN A GRAPH !
// Method of https://www.geeksforgeeks.org/detect-cycle-in-a-graph/


#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>

using namespace std;

const int n=6;
vector<vector<int>> graph(n);

void addEdge(int u,int v){
    graph[u].push_back(v);
}


void display(){
    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check_cycle_util(int s,vector<bool> &vis,vector<bool> &recstack){

    if(!vis[s])
    {
        
        vis[s]=true;
        recstack[s]=true;
        
        for(int v:graph[s])
        {
            if(!vis[v])
               return (check_cycle_util(v,vis,recstack));
            else if(recstack[v])
                return true;
        }
    }
    
    recstack[s]=false;
    return false;

}

bool check_cycle(){
    
    vector<bool> vis(n,false);
    vector<bool> recstack(n,false);

    bool res=false;
    
    for(int i=0;i<n;i++){
        res=res||check_cycle_util(i,vis,recstack);
    }
    
    return res;
}


int main(){
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    
    

    vector<vector<int>> graph(n,vector<int>());
    vector<int> color(n,-1);
    
    
    queue<int> q;
    
    display();
    
    cout<<endl<<check_cycle();
}
