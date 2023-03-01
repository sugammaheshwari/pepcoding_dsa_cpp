
// To check if a Binary Tree is Binary search Tree or NOT !!!

#include<iostream>
#include<queue>

using namespace std;
struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT=NULL;



// METHOD 1 : to recursively check for left subtree and right subtree and then recursively calling the main function !!! , inefficient
// METHOD 2: By using upper and lower bound (limits) to check each and every node if it lies in the limit.

// BEST METHOD (3): Use the inorder Traversal and check the resultant sequence should be in increasing order ,if yes then you have a BST !!!


int check_lst(BST * r,int x){
    if(r==NULL){
        return(1);
    }
    
    if( r->data <= x && check_lst(r->left,x) && check_lst(r->right,x)){
        return(1);
    }
    else{
        return(0);
    }
}

int check_rst(BST *r,int x){
    if(r==NULL){
          return(1);
      }
      
      if( r->data >= x && check_rst(r->left,x) && check_rst(r->right,x)){
          return(1);
      }
      else{
          return(0);
      }
}

int check_bst(BST *r){
    
    if(r==NULL){
        return(1);
    }
    if (check_bst(r->left) && check_bst(r->right) && check_lst(r->left,r->data) && check_rst(r->right,r->data))
        return(1);
    else{
        return(0);
    }
}
        



int main(){
    
    BST *t=new BST();
    t->data=3;
    ROOT=t;
    
    BST *a=new BST();
    t->right=a;
    a->data=5;
    
    
    BST *b=new BST();
    ROOT->left=b;
    b->data=2;
    
    
    BST *c=new BST();
    ROOT->left->right=c;
    c->data=4;
    
    cout<<endl<<check_bst(ROOT);            // zero  means not a BST ;
}


