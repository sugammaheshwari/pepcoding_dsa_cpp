
/*  GREEDY ALGORHITMS FOR FINDING MINIMUM COST SPANNING TREES !!!
 (CONDITIONS : the given graph must be weighted, connected and undirected )
 
 What is a Spanning Tree?
 A spanning tree is a subgraph of a graph which connects all the vertices of a graph with minimun no of edges possible!
 
 Given a graph G(V,E) then what are the no of spanning trees possible?
 Let no of cycle,edges,vertices in the graph be c,e,v respectively
 then no of spanning trees = (e)C(v-1) - c  , where C- chose v-1 from e , ie combination formulae.
 
 What is a minimum Cost Spanning Tree?
 Select a spanning tree from all the possible combinations with the minimum cost in the given weighted graph, you get the MST.
 The above process would be too slow for a big graph , thus comes Greedy alogithm into play - Prims and Kruskals algorithm

 Kruskals Algorithm
 
 here we have used comparitor function to sort edge list in increasing order
 cycle detection is done through DSU technique
 time complexity of kruskal's algo to find minimum cost  or MST is 0(nlog(n))


 */

#include<iostream>
#include<vector>
using namespace std;


class edge{
public:
    int u;
    int v;
    int w;
    
    edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
    
};

vector<edge>edge_list;

const int n=5;

vector<int> parent(n);
vector<int> size(n,1);
int cost=0;

bool comparator(edge e1,edge e2)
{
    return e1.w<e2.w;
}

int find_parent(int u)
{
    if(parent[u]==u)
        return u;
    
    int p=find_parent(parent[u]);
    parent[u]=p;
    return p;
}

void merge_(int p1,int p2)
{
    if(size[p1]>=size[p2])
    {
        parent[p2]=p1;
        size[p1]+=size[p2];
    }
    else{
        parent[p1]=p2;
        size[p2]+=size[p1];
    }
}

int kruskals_algo()
{
    for(edge ed:edge_list)
    {
        int p1=find_parent(ed.u);
        int p2=find_parent(ed.v);
        
        if(p1!=p2)
        {
            merge_(p1, p2);
            cost+=ed.w;
        }
        else
            continue;
    }
    
    return cost;
}


int main(){
    
    for(int i=0;i<n;i++)
        parent[i]=i;

    edge_list.push_back(edge(0,1,2));
    edge_list.push_back(edge(1,2,6));
    edge_list.push_back(edge(2,3,3));
    edge_list.push_back(edge(1,4,4));
    edge_list.push_back(edge(3,4,5));
    edge_list.push_back(edge(0,3,1));

    
    sort(edge_list.begin(),edge_list.end(),comparator);
    
    kruskals_algo();
    cout<<"\n the minimum cost using kruskals algo is :"<<cost<<endl;
    
    
    
}

