
//  Median of Two Sorted Arrays
// Youtube Explanation Link : https://www.youtube.com/watch?v=LPFhl65R7ww&t=481s


class Solution {
public:
    double findMedianSortedArrays(vector<int>& X, vector<int>& Y) {
  
        if(X.size()>Y.size()) return findMedianSortedArrays(Y,X);
        
        int x=X.size(),y=Y.size();
        
        int low=0,high=x;          // binary searching on the smaller array input X
        
        while(low<=high)
        {
            int px=low+(high-low)/2;
            int py=(x+y+1)/2-px;                //adding 1 to handle odd and even length of combined length of X,Y case.
            
            int maxLeftX = (px==0) ?  INT_MIN : X[px-1];
            int minRightX = (px==x) ? INT_MAX : X[px];
            
            int maxLeftY = (py==0) ? INT_MIN : Y[py-1];
            int minRightY = (py==y) ? INT_MAX : Y[py];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
            {
                // exit condition for binary search
                if( (x+y)&1 ) return max(maxLeftX,maxLeftY);
                return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2;
            }
            else if(maxLeftX>minRightY) high=px-1;
            else low=px+1;
        }
        
        return -1;
    }
};
