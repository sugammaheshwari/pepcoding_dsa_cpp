
/*
 
 LEETCODE PREMIUM : LARGEST BST IN A GIVEN BINARY TREE
 SOLUTION IS UNTESTESTED CAUSE ITS A PREMIUM LEETCODE PROBLEM
 
 SELF CODED SOLUTION
 
 
 GEEKS REFERENCE LINK : https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
 
 */


#include<iostream>
#include<vector>
using namespace std;

struct node{
    int val;
    node *left,*right;
    
    node(int val)
    {
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

int LargestBSTLen=0;

vector<int> LargestBST(node *r)
{
    if(!r->left && !r->right) {    LargestBSTLen=max(LargestBSTLen,1); return {1,r->val,r->val}; }
    
    if(!r->right)
    {
        vector<int> l_vec=LargestBST(r->left);
        if(l_vec[1]<r->val && l_vec[2]<r->val)
        {
            LargestBSTLen=max(LargestBSTLen,l_vec[0]+1);
            return {l_vec[0]+1,l_vec[1],r->val};
        }
        return {1,r->val,r->val};
    }
    
    if(!r->left)
    {
        vector<int> r_vec=LargestBST(r->right);
        if(r_vec[1]>r->val && r_vec[2]>r->val)
        {
            LargestBSTLen=max(LargestBSTLen,r_vec[0]+1);
            return {r_vec[0]+1,r->val,r_vec[2]};
        }
        return {1,r->val,r->val};
    }
    
    vector<int> l_vec=LargestBST(r->left),r_vec=LargestBST(r->right);
    
    if(l_vec[2]<r->val && r_vec[1]>r->val)
    {
        LargestBSTLen=max(LargestBSTLen,l_vec[0]+1+r_vec[0]);
        return {l_vec[0]+1+r_vec[0],l_vec[1],r_vec[2]};
    }
   
    return {1,r->val,r->val};
}


int main()
{
    node *root = new node(50);
    root->left = new node(10);
    root->right = new node(60);
    root->left->left = new node(5);
    root->left->right = new node(20);
    root->right->left = new node(55);
    root->right->left->left = new node(45);
    root->right->right = new node(70);
    root->right->right->left = new node(65);
    root->right->right->right = new node(80);
    
    LargestBSTLen=0;
    LargestBST(root);
    cout<<LargestBSTLen<<endl;
    
}
