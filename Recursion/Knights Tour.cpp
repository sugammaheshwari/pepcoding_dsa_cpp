
// Knight's Tour Problem

#include<iostream>
#include<vector>
using namespace std;

vector<vector<bool>> b(8,vector<bool>(8,false));

// here this perticular clock-wise pattern of moves is needed to be followed , to give answer
// else it will lead in TLE.
vector<vector<int>> moves={{-2,+1},{-1,+2},{+1,+2},{+2,+1},{+2,-1},{+1,-2},{-1,-2},{-2,-1}};

bool place(vector<vector<bool>> &b,int i,int j,int count)
{
    if(count==64)
        return true;
    
    bool res=false;
    for(int m=0;m<moves.size() && !res;m++)
    {
        int x=i+moves[m][0],y=j+moves[m][1];
        if(x<0 || x>=8 || y>=8 || y<0 || b[x][y])
            continue;
        b[x][y]=true;
        res=res || place(b,x,y,count+1);
        b[x][y]=false;
    }
    
    return res;
}


int main()
{
    // backtracking doesnt solve this problem entirly , it works for some of cases
    // one of it is 0,0 as starting position.
    b[0][0]=true;   // initial placement of knight.
    cout<<place(b,0,0,1);
}
