#include<iostream>
using namespace std;

struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT=NULL;

int left_depth_global=-1;

void left_view(BST *r,int depth){
    if(r==NULL) return ;
    
    if(depth>left_depth_global) {
        cout<<endl<<r->data;
        left_depth_global=depth;
    }
    
    left_view(r->left, depth+1);
    left_view(r->right, depth+1);
}

int right_depth_global=-1;

void right_view(BST *r,int depth){
    
    if(r==NULL) return;
    
    if(depth>right_depth_global){
        cout<<endl<<r->data;
        right_depth_global=depth;
    }
    
    right_view(r->right, depth+1);
    right_view(r->left, depth+1);
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

int main(){
    ROOT=insert(ROOT,10);
    ROOT=insert(ROOT,5);
    ROOT=insert(ROOT,1);
    ROOT=insert(ROOT,7);
    ROOT=insert(ROOT,40);
    ROOT=insert(ROOT,50);
    ROOT=insert(ROOT,45);
    
    right_view(ROOT, 0);
}
