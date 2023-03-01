
/* Floyd Warshall Algorithm | DP-16

 The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
 
 */

#include<iostream>
#include<vector>
using namespace std;

#define INF 9999
// here 9999 represents INT_MAX


int main()
{
    int n=4;
    
    // graph representation using adjacency list !!!
    vector<vector<int>> g={ {0, 5, INF, 10},
                            {INF, 0, 3, INF},
                            {INF, INF, 0, 1},
                            {INF, INF, INF, 0}
                          };
    
    vector<vector<int>> d;
    d=g;
    
    for(int mid=0;mid<n;mid++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][mid]+d[mid][j]<d[i][j])
                    d[i][j]=d[i][mid]+d[mid][j];
            
    
    
    cout<<"The shortes distance bw pair of vertices is represented in the adjacency matrix below"<<endl;
    
    for(auto x:d){
        for(auto y:x)
            cout<<y<<":";
        cout<<endl;
    }
    
    return 0;
    
}

