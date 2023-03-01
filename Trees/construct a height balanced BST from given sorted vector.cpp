
/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 Example:

 Given the sorted array: [-10,-3,0,5,9],

 One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

       0
      / \
    -3   9
    /   /
  -10  5
 
 */

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create_tree(vector<int> &nums,int sid,int eid){
        
    
    if(sid>eid) return NULL;

    int m=(sid+eid)/2;
    TreeNode *root=new TreeNode(nums[m]);
    if(sid==eid) return  root;
    
    root->left=create_tree(nums,sid,m-1);
    root->right=create_tree(nums,m+1,eid);
        
    return root;
        
}

void show_tree(TreeNode * r){
    
    if(r==NULL) return ;
    show_tree(r->left);
    show_tree(r->right);
    cout<<r->val<<endl;


}


int main(){
    vector<int> vec={1,5,8,9,11,16};
    
    TreeNode *r=create_tree(vec, 0, 5);
    
    show_tree(r);
    

}

