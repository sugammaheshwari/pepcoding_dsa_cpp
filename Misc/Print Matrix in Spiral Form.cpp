
/*
 
 Print a given matrix in spiral form
 Input:  1    2   3   4
         5    6   7   8
         9   10  11  12
         13  14  15  16
 Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 
 */


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> v={ { 1, 2, 3, 4 },
                            { 5, 6, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 } };
    
    int n=int(v.size());
    
    int left=0,right=n-1;
    int top=0,down=n-1;
    int dir=0;
    
    while(top<=down && left<=right)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
                cout<<v[top][i]<<" ";
            top++;
            dir=1;
        }
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
                cout<<v[i][right]<<" ";
            right--;
            dir=2;
        }
        else if(dir==2)
        {
            for(int i=right;i>=left;i--)
                cout<<v[down][i]<<" ";
            down--;
            dir=3;
        }
        else
        {
            for(int i=down;i>=top;i--)
            cout<<v[i][left]<<" ";
            left++;
            dir=0;
        }
        
        
    }
    
    
}
