

// LEETCODE : 114 https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include<iostream>
using namespace std;

struct node
{
    int val;
    node *left,*right;
    
    node(int x)
    {
        val=x;
        left=NULL;right=NULL;
    }
};

void flatten(node *r)
{
    if(r==NULL)
        return ;
    
    if(!r->left)
    {
        flatten(r->left);
        node *old_right=r->right;
        r->right=r->left;
        r->left=NULL;
        
        node *t=r->right;
        while(t->right!=NULL)
            t=t->right;
        t->right=old_right;
    }
    
    flatten(r->right);
}
