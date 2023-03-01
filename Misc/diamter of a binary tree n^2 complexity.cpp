// finding diameter of a binary tree , efficiency n^2 complexity
// better method available on geeksforgeeks


#include<iostream>
#include<cmath>

using namespace std;

struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT;


BST *insert(BST *r,int x){
    
    if(r==NULL){
        BST *temp=new BST;
        temp->data=x;
        r=temp;
        return(r);
    }
    
    else if(r->data<x){
        r->right=insert(r->right,x);
    }
    else if(r->data>x){
        r->left=insert(r->left,x);
    }
    return(r);          // this handles my case of duplicay #thug life
}


int find_height(BST *r){
    if(r==NULL) return(0);
    return( fmax(find_height(r->left),find_height(r->right)) + 1 );
}


void DFS(BST *r){
    if(r==NULL) return;
    DFS(r->left);
    cout<<endl<<r->data;
    DFS(r->right);
}


int diameter(BST * r){
    if(r==NULL) return 0;
    int l_h=find_height(r->left);
    int r_h=find_height(r->right);
    int l_d=diameter(r->left);
    int r_d=diameter(r->right);
    int fd=max(l_h+r_h+1,max(l_d,r_d));
    
    return fd;
}

int main(){

    ROOT=insert(ROOT,10);
    
    ROOT=insert(ROOT,5);
    ROOT=insert(ROOT,11);
    ROOT=insert(ROOT,7);
    ROOT=insert(ROOT,-1);
    
    cout<<"\n the diameter of the tree is :"<<diameter(ROOT);
    
    
}

    
