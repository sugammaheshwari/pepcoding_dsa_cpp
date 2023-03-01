
/*
 
 Print K’th element in spiral form of matrix
 GEEKS : https://www.geeksforgeeks.org/print-kth-element-spiral-form-matrix/
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
    
    int n=int(v.size()); int K=0;
    
    while(K<16)
    {
        K++;
        int count=0;
        int left=0,right=n-1;
        int top=0,down=n-1;
        int dir=0;
        
        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                if(count+right-left+1<K) count+=right-left+1;
                else break;
                top++;dir=1;
            }
            else if(dir==1)
            {
                if(count+down-top+1<K) count+=down-top+1;
                else break;
                right--;dir=2;
            }
            else if(dir==2)
            {
                if(count+right-left+1<K) count+=right-left+1;
                else break;
                down--;dir=3;
            }
            else
            {
                if(count+down-top+1<K) count+=down-top+1;
                else break;
                left++;dir=0;
            }
        }
        
        cout<<"The "<<K<<"element after spiral traversal (without actual traversal)  is :";
        
        if(dir==0) cout<<v[top][left+(K-count-1)];
        else if (dir==1) cout<<v[top+(K-count-1)][right];
        else if(dir==2) cout<<v[down][right-(K-count)+1];
        else cout<<v[down-(K-count)+1][left];
        cout<<endl;
    }
}
