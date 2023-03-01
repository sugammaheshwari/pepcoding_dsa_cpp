
#include<iostream>
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

bool f_tree(BST * r,int x){
    if(r==NULL)return (0);
    if(r->data<x) return(f_tree(r->right, x));
    if(r->data>x) return(f_tree(r->left, x));
    if(r->data==x) return(1);
    return(0);
}

BST * find_min(BST *r){
    if(r==NULL) return r;
    BST *t=r;
    while(t->left!=NULL){
        t=t->left;
    }
    return(t);
}

BST *delete_in_BST(BST *r,int x){
    if(r==NULL) return r;
    else if (r->data>x) r->left=delete_in_BST(r->left, x);
    else if (r->data<x) r->right=delete_in_BST(r->right, x);
    else{
        if(r->left ==NULL && r->right==NULL){
            r=NULL;
        }
        if (r!=NULL && r->right==NULL)r=r->left;
        if(r!=NULL && r->left==NULL) r=r->right;
       
        else{
            // case of two children
            if(r!=NULL){
            BST * s=find_min(r->right);
            r->data=s->data;
            r->right=delete_in_BST(r->right, s->data);}
        }
    }
    return(r);
}






void DFS(BST *r){
    if(r==NULL) return;
    DFS(r->left);
    cout<<endl<<r->data;
    DFS(r->right);
}


int main(){
    ROOT=insert(ROOT, 10);
    //cout<<endl<<ROOT->data;
    ROOT=insert(ROOT, 20);
    ROOT=insert(ROOT,25);
    
    ROOT=insert(ROOT, 5);
    ROOT=insert(ROOT,-5);
    //ROOT=insert(ROOT,20);     //check duplicacy output when doing traversal prac
    //cout<<endl<<ROOT->right->data;
    //cout<<endl<<f_tree(ROOT, 20);
    DFS(ROOT);
    //cout<<endl<<find_min(ROOT)->data;
    ROOT=delete_in_BST(ROOT, 25);
    
    cout<<endl<<"after deletion:";
    DFS(ROOT);
}
    
