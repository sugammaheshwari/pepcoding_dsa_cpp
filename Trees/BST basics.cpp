
#include<iostream>
#include<math.h>
using namespace std;

struct node{
    int val;
    node *left=NULL;
    node *right=NULL;
}*root=NULL;

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

void show_bst_dfs(node *r){
    
    if(r==NULL) return;
    
    node *r_=r;
    show_bst_dfs(r_->left);
    cout<<endl<<r_->val;
    show_bst_dfs(r_->right);
    
}

node *find_max_of_tree(node *r){
    if(r->right==NULL) return r;
    node *r_=r;
    while(r_->right!=NULL){
        r_=r_->right;
    }
    return r_;
}


node *delete_bst(node *r,int x){
    
    if(r==NULL) return r;
    else if(r->val<x) r->right=delete_bst(r->right, x);
    else if(r->val>x) r->left=delete_bst(r->left, x);
    else{
        if(r->left==NULL && r->right==NULL){                // case of leaf node
            r=NULL;
        }
        
        else if(r->left==NULL){                         // has single child
            r=r->right;
        }
        
        else if(r->right==NULL){                        // has single child
            r=r->left;
        }
        
        else{                                       // crucial case when node has both left and right children !
            node *temp=find_max_of_tree(r->left);          // can swap current node with maximum of left subtree
            r->val=temp->val;                                   // or minimum of right subtree
            r->left=delete_bst(r->left, temp->val);                     // recusive final fix call !!
        }
    }
    return r;
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
    root=insert_BST(root, 8);
    root=insert_BST(root, -3);
    //root=insert_BST(root, 0);


    root=delete_bst(root, 7);
    
    
    show_bst_dfs(root);
    
    cout<<endl<<"height of tree is:"<<height_of_BST(root);
    
}


