
//Lowest Common Ancestor Problem for a BST


#include<iostream>
#include<vector>
using namespace std;


struct node{
    int val;
    node * left=NULL;
    node *right=NULL;
}*root;

node *create_node(int x){
    
    node *t=new node();
    t->val=x;
    return(t);
}


node *insert_BST(node *r,int x){
    
    if(r==NULL){
        return(create_node(x));
    }
        
    if(r->val<x){
        r->right=insert_BST(r->right, x);
    }
    
    if(r->val>x){
        r->left=insert_BST(r->left, x);
    }
    
    return r;
}

node *LCA_BST(node * r,int p, int q){
    
    if(r==NULL) return r;
    
    if(r->val > p && r->val >q ) return (LCA_BST(r->left,p,q));
    if(r->val <p && r->val <q ) return (LCA_BST(r->right,p,q));
    
    return r;
}




int main(){
    
    root=insert_BST(root, 3);
    root=insert_BST(root, 5);
    root=insert_BST(root, 1);
    root=insert_BST(root, 6);
    root=insert_BST(root, 2);
    root=insert_BST(root, 0);
    root=insert_BST(root, 8);
    root=insert_BST(root, 7);
    root=insert_BST(root, 4);


    cout<<endl<<LCA_BST(root,0,6)->val;

    
    
}
