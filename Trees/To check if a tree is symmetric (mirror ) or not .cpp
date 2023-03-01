
// To check if a binary tree is symetric or not !!!
// recursive method is easy but slower , iterative is more efficient !
// PLEASE NOTE : here simple inoreder traversal doesnt work , we need to modify it
// so that it can work properly

#include<vector>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    
    node(int x)
    {
        data=x;
        left=NULL;right=NULL;
    }
};


// Method 1 : using recursion !!!

bool check(node *r1,node *r2)
{
    if(!r1 && !r2)
        return true;
    if( !r1 || !r2 || r1->data!=r2->data )
        return false;
    
    return check(r1->left,r2->right) && check(r1->right,r2->left);
}

bool is_sysmetric(node *root)
{
    return check(root,root);
}


// method 2 , by traversing the tree and checking the mirror images components
// of the tree smartly as follows!!!

class Solution {
public:
    
    vector<pair<int,int>> pre;
    
    void preorder(node *r,int lvl)
    {
        if(r==NULL)
            return;
        
        preorder(r->left,lvl-1);
        pre.push_back({r->data,lvl});
        preorder(r->right,lvl+1);
    }
    
    bool isSymmetric(node* root)
    {

        preorder(root,0);

        for(int i=0,j=int(pre.size()-1);i<j;i++,j--)
            if(pre[i].first!=pre[j].first || pre[i].second!=-1*pre[j].second)
                return false;
        
        return true;
    }
};
