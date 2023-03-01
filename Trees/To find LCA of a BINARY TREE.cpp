
// To find lowest common ancestor of a binary tree !!!
//Note its different and a lill tricky than finding LCA for a BST !!!

#include<iostream>
using namespace std;

struct node
{
    int val;
    node *l,*r;
    
    node(int x)
    {
        val=x;
        l=r=NULL;
    }
};

// method 1
// it is more space and runtime efficient but it destroys the original structure of binary tree

node *find(node *root,node *p,node *q)
{
    if(!root)
        return root;
    if(root==p || root==q)
        return root;
    root->l=find(root->l,p,q);              // due to these two statement
    root->r=find(root->r,p,q);                  // original structure is modified!
    
    if(root->l && root->r)
        return root;
    return root->l==NULL?root->r:root->l;
}

// method 2
// it preserves the original structure but uses more space and time !!!
node *find_2(node *root,node *p,node *q)
{
    if(!root)
        return root;
    if(root==p || root==q)
        return root;
    node *le=find(root->l,p,q);
    node *re=find(root->r,p,q);                  // original structure is not modified
    
    if(le && re)
        return root;
    return le==NULL?re:le;
}

// LCA Method 3
/*
        only describing the method here
 
 find root to node path for both the nodes and start iterating over the vertices in the path ( if node1_path[i]==node2_path[i]) then i++
 else
    return node1_path[i] as the answer of the lowest common ancestor to the problem!
 */

