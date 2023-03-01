
// Geeks : to Find all the paths for a rat in a maze in increasing order : (ie inc alphabatical order !!!)
// link :https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


#include<iostream>
#include<vector>
using namespace std;

#define max 4

vector<string> ans;

void find(int m[max][max],int n,int i,int j,string a)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(a);
        return;
    }
    
    m[i][j]=0;                          // imp step to mark the visited cell as zero else stack overflow (1->2 then 2->1 , endless loop) !!!
    
    if(i+1<n && m[i+1][j])                  // here we need to make calls in this order only for alphabatical order !!
        find(m,n,i+1,j,a+"D");               //   D->L->R->U order 
    if(j-1>=0 && m[i][j-1])
        find(m,n,i,j-1,a+"L");
    if(j+1<n && m[i][j+1])
        find(m,n,i,j+1,a+"R");
    if(i-1>=0 && m[i-1][j])
        find(m,n,i-1,j,a+"U");
    
    m[i][j]=1;                      // imp step to reverse the visited cell back to 1 so that all the paths can be traced !
}





int main()
{
    int m[max][max]={{1,0,0,0},{1,1,0,1},{0,1,1,1},{1,1,1,1}};
    
    if(!m[0][0])
        cout<<"no solution !";
    else
        find(m,max,0,0,"");
    cout<<"The posssible solution are :"<<endl;
    for(auto x:ans)
        cout<<x<<endl;
    
    
}
