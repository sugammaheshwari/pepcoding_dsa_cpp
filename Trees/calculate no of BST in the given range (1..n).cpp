
/*
 Calculate Unique Binary Search Trees
 Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

 Example:

 Input: 3
 Output: 5
 Explanation:
 Given n = 3, there are a total of 5 unique BST's:

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
 
 */


#include<iostream>
#include<vector>

using namespace std;

int numTrees(int n){
    
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    
    int count=0;
    for(int i=1;i<=n;i++){
        
        int l_r=numTrees(i-1);
        int r_r=numTrees(n-i);
        
        if(l_r==0 && r_r!=0) count+=r_r;
        else if(r_r==0 && l_r!=0) count+=l_r;
        else count+=l_r*r_r;
    }
    
    return count;
    
}

int main(){
    
    cout<<endl<<numTrees(5);
}


/* another leet code solution using hashmap

int numTrees_02(int n) {
    unordered_map<int,int> nums;
    nums[0] = 1; //if there is no pair then its 1 possible combination
    nums[1] = 1; //like wise if there is a pair then its 1 possible combination
    for(int i = 2; i <= n; i ++){ //start from 2 since we know n = 1
        int sum = 0;
        for(int j = 1; j <= i; j++){
            sum += nums[j-1] * nums[i-j];
        }
        nums[i] = sum;
    }
    return nums[n];
}
*/






