
/*  GREEDY ALGORHITMS FOR FINDING MINIMUM COST SPANNING TREES !!!
 
 What is a Spanning Tree?
 A spanning tree is a subgraph of a graph which connects all the vertices of a graph with minimun no of edges possible!
 
 Given a graph G(V,E) then what are the no of spanning trees possible?
 Let no of cycle,edges,vertices in the graph be c,e,v respectively
 then no of spanning trees = (e)C(v-1) - c  , where C chose v-1 from e , ie combination formulae.
 
 What is a minimum Cost Spanning Tree?
 Select a spanning tree from all the possible combinations with the minimum cost in the given weighted graph, you get the MST.
 The above process would be too slow for a big graph , thus comes Greedy alogithm into play - Prims and Kruskals algorithm
 
 #GREEDY ALGORITHMS
 ( to find minimum spanning tree for a given G(V,E) )
 
1. PRIMS ALGORITHM
 youtube video link for algo explaination : https://www.youtube.com/watch?v=mqKPgW3C5ps&t=596s
 
 Time Complexity  : O(ElogV)
 Prim’s Algorithm is preferred when-
 The graph is dense.
 There are large number of edges in the graph.
  
 */


#include<iostream>
#include<vector>
using namespace std;

const int n=5;
vector<vector<pair<int,int>>> g(n);

void add_edge(int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

int find_min_weight_idx(vector<pair<int,int>> &data,vector<bool> &un_vis)   // returns idx of min weight in un-visted vector
{
    int t=INT_MAX;
    int min_idx=-1;
    
    for(int i=0;i<n;i++)
        if(un_vis[i] && data[i].second<t)
        {
            t=data[i].second;
            min_idx=i;
        }

    return min_idx;
}

vector<pair<int,int>> vertex_data(n,{-1,INT_MAX});

void prims_algo(int s)                  // s is the starting vertex's index for prims algorithm !
{
    vector<bool> vis(n,false);
    vector<bool> un_vis(n,true);
    
    vertex_data[s].first=s;
    vertex_data[s].second=0;
    
    int count=0;
    
    while(count<n)
    {
        int idx=find_min_weight_idx(vertex_data, un_vis);
        vis[idx]=true; un_vis[idx]=false;
        
        for(auto vec:g[idx])
        {
            int i=vec.first;
            int w=vec.second;
            if(un_vis[i] && vertex_data[i].second>w)
            {
                vertex_data[i].first=idx;           // updated parent
                vertex_data[i].second=w;            // updated weight
            }
        }
        
        count++;
    }
}


int main()
{
    add_edge(0,1,2);
    add_edge(0,2,8);
    add_edge(1,2,3);
    add_edge(1,3,2);                    //    add_edge(1,3,6); , for different spanning tree !
    add_edge(2,3,3);
    add_edge(2,4,1);
    add_edge(3,4,1);
    
    prims_algo(0);
   
    /*  IMP THING TO NOTICE !!!!
     
     here the goal of prims algo is to generate MST so the question may arrise which source to be taken for prims algorithms
     The beauty of this alogithm is that you can take any vertex as source and run the algorithm ans would be same
     
     Just think about it , we are generating MST from a given graph so whichever vertex we chose and generate our MST our answer would always come out to be the
     same !!!!
     */
    
    int cost=0;
    
    for(int i=0;i<vertex_data.size();i++)
    {
        cout<<i<<":"<<vertex_data[i].first<<":"<<vertex_data[i].second<<endl;
        cost+=vertex_data[i].second;
    }
    
    cout<<" the minimum cost is :"<<cost<<endl;
    
    return 1;
    
}
