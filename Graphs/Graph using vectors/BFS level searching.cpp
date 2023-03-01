

// BFS level searching an element !!!!
// Neat Trick !

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> g(7);

void add_edge(int u,int v)
{
    g[u].push_back(v);
}


int BFS_with_lvls(int s,int d)
{
    queue<int> q;
    vector<bool> vis(7,false);
    int lvl=0;
    if(s==d)
        return lvl;
    q.push(s);
    vis[s]=true;
    
    while(!q.empty())
    {
        int qsize=int(q.size());
        for(int i=0;i<qsize;i++)
        {
            int curr=q.front();
            q.pop();
            for(auto x:g[curr]){
                if(!vis[x] && x==d)
                    return lvl;
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
        lvl++;
    }
    return -1;
}



int main()
{
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(2, 4);
    add_edge(3, 5);
    add_edge(4, 6);
    
    
    cout<<"the level at which the destination node was found :"<<BFS_with_lvls(0,6)<<endl;
}
