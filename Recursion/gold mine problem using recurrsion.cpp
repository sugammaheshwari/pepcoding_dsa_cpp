
// GOLD MINE problem
// link : https://www.geeksforgeeks.org/gold-mine-problem/


#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mat =   {{1, 3, 3},
 {2, 1, 4},
{0, 6, 4}};

int m=3;
int n=3;

int collect_gold(int sr,int sc,int m,int n,int gold)
{
    if(sc==n-1)
    {
        gold+=mat[sr][sc];
        return gold;
    }
    
    int p1=0,p2=0,p3=0;
    if(sr+1<m && sc+1<n)
        p1=collect_gold(sr+1,sc+1,m,n,gold+mat[sr][sc]);
    if(sr-1>=0 && sc+1<n)
        p2=collect_gold(sr-1,sc+1,m,n,gold+mat[sr][sc]);
    if(sc+1<m)
        p3=collect_gold(sr,sc+1,m,n,gold+mat[sr][sc]);
        
    return max(max(p1,p2),p3);
}

int main(){
    
    string path="";
    int gold=0;
    
    for(int i=0;i<m;i++)
        gold=max(gold,collect_gold(i,0,m,n,0));
    
    cout<<"max amount that can be collected is :"<<gold<<endl;
}
