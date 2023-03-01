

// 304. Range Sum Query 2D - Immutable
/*
 Given a 2D matrix matrix, handle multiple queries of the following type:

 Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 Implement the NumMatrix class:

 NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
 int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

 */

#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
public:
    
    vector<vector<int>> V;
    vector<vector<int>> dp;
    int m,n;
    
    NumMatrix(vector<vector<int>>& matrix)
    {
        V=matrix;
        m=matrix.size();n=matrix[0].size();
        dp.resize(m,vector<int>(n));
        dp[0][0]=V[0][0];
        
        for(int j=1;j<n;j++) dp[0][j]=dp[0][j-1]+V[0][j];
        for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+V[i][0];
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]-dp[i-1][j-1] + dp[i][j-1] + V[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if(row1==0 && col1==0)
            return dp[row2][col2];
        else if(row1==0)
            return dp[row2][col2] - dp[row2][col1-1];
        else if(col1==0)
            return dp[row2][col2]- dp[row1-1][col2];
    
        return dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
    
    }
};
