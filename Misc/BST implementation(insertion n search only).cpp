
//implementation of BST

#include<iostream>
using namespace std;

struct BST{
    int data;
    BST *left;
    BST *right;
}*ROOT;

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

bool search(BST *r,int x){
    if(r==NULL)return(0);
    else if(r->data==x) return(1);
    else if (r->data>x) return(search(r->left,x));
    else return(search(r->right,x));
}

int main(){
        
    ROOT=insert(ROOT,10);
    ROOT=insert(ROOT,20);
    ROOT=insert(ROOT,30);
    ROOT=insert(ROOT,5);
    
    cout<<endl<<((ROOT->right)->right)->data;
    cout<<endl<<ROOT->left->data;
    
    cout<<endl<<search(ROOT,31);
}
