
// BFS of a BST using queue

#include<iostream>

using namespace std;
struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT=NULL;

void D_F_S(BST *r){             // inorder traversal
    if(r==NULL) return;
    D_F_S(r->left);
    cout<<endl<<r->data;
    D_F_S(r->right);
}

BST* insert(BST *r,int x){
    if(r==NULL){
        r=new BST();
        r->data=x;
    }
    
    else if(x<=r->data){
        r->left=insert(r->left,x);
    }
    else if(x>r->data){
        r->right=insert(r->right,x);
    }
    return(r);
}

BST *fin_min(BST *r){
    while(r->left!=NULL){
        r=r->left;
    }
    return(r);
}


/*
 in the function delete there are two things to take care of
 1:
    in the condition use if and then else if because first if condition gets checked and then only control reached to the else if part and so on...
 
2: else{
        else if( r->left==NULL)  vs else if ( r->right!=NULL )
        looks the same statement but the latter doesnt work because i false in the base case of
        when trying to delete ( tree with 2 child , left and right ) .
 */


BST* Delete(BST *r , int x){
    if(r==NULL)return r;
    else if(r->data>x) r->left=Delete(r->left,x);
    else if (r->data<x) r->right=Delete(r->right,x);
    else{
        if(r->left==NULL && r->right==NULL){
            BST *t=r;
            r=NULL;
            delete(t);
        }
        else if(r->left==NULL){
            BST *t=r;
            r=r->right;
            delete(t);
        }
        else if(r->right==NULL){
            BST *t=r;
            r=r->left;
            delete(t);
        }
        else{
            BST *t=fin_min(r->right);
            r->data=t->data;
            r->right=Delete(r->right, t->data);
        }
    }
    return(r);
}

int main(){
    ROOT=insert(ROOT, 10);
    ROOT=insert(ROOT,5);
    ROOT=insert(ROOT, 7);
    ROOT=insert(ROOT,4);
    ROOT=insert(ROOT, 112);
    ROOT=insert(ROOT,-5);
    D_F_S(ROOT);
    Delete(ROOT, 4);
    cout<<endl<<"after deletion";
    D_F_S(ROOT);
}



