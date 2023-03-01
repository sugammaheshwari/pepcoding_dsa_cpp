
// insertion into BST and adding height of each node while inserting the node itself

#include<iostream>
#include<math.h>
using namespace std;

struct node{
    int val;
    node *left=NULL;
    node *right=NULL;
    int height=-1;
    
}*root=NULL;

node *create_node(int x){
    
    node *t=new node();
    t->val=x;
    t->height=0;
    return(t);
}

node *insert_BST(node *r,int x){
    
    if(r==NULL){
        r=create_node(x);
    }
        
    else if(r->val<x){
        r->right=insert_BST(r->right, x);
    }
    
    else if(r->val>x){
        r->left=insert_BST(r->left, x);
    }
    
    if(r->left!=NULL && r->right!=NULL )
        r->height=max(r->left->height,r->right->height)+1;
    if(r->left == NULL  && r->right!=NULL) r->height=r->right->height+1;
    if(r->right == NULL  && r->left!=NULL)r->height=r->left->height+1;

    return r;
}

void show_bst_dfs(node *r){
    
    if(r==NULL) return;
    
    node *r_=r;
    show_bst_dfs(r_->left);
    cout<<endl<<r_->val<<"with height :"<<r_->height;
    show_bst_dfs(r_->right);
    
}



int height_of_BST(node * r){
    
    if(r==NULL) return (-1);
    
    int lh=0;
    int rh=0;
    
    lh=height_of_BST(r->left);
    rh=height_of_BST(r->right);
    
    return ( max(lh,rh) +1 ) ;
}


int main(){
    
    root=insert_BST(root, 2);
    root=insert_BST(root, 7);
    root=insert_BST(root, -1);
    root=insert_BST(root, 5);


    
    
    show_bst_dfs(root);
    
}


