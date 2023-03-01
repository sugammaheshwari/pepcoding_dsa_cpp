/*
 
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 Note: A leaf is a node with no children.

 Example:

 Given the below binary tree and sum = 22,

       5
      / \
     4   8
    /   / \
   11  13  4
  /  \    / \
 7    2  5   1
 Return:

 [
    [5,4,11,2],
    [5,8,4,5]
 ]
 
 */ // leet code submitted solution !

#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > ans;

void find(TreeNode * r,int rem,vector<int> a_){
    
    if(r!=NULL){
        rem-=r->val;
        a_.push_back(r->val);
        if(rem==0 && r->left==NULL && r->right==NULL) ans.push_back(a_);
        find(r->left,rem,a_);
        find(r->right,rem,a_);
    }
}


vector<vector<int>> pathSum(TreeNode* root, int sum) {
    
    vector <int> a_;
    find(root,sum,a_);
    return(ans);
        
}
