
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

int find_height(BST *r){
    if(r==NULL) return(0);
    return( fmax(find_height(r->left),find_height(r->right)) + 1 );
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


bool is_subtree_lesser(BST *r,int x){
    if(r==NULL) return 1;
    if(r->data<x && is_subtree_lesser(r->left, x) && is_subtree_lesser(r->right, x) ) return 1;
    else
        return 0;
}
bool is_subtree_greater(BST *r,int x){
    if(r==NULL) return 1;
    if(r->data>x && is_subtree_greater(r->left, x) && is_subtree_greater(r->right, x) ) return 1;
    else
        return 0;
}

bool is_binary_tree(BST *r){
    
    if(r==NULL) return(1);
    
    if(is_subtree_lesser(r->left,r->data) && is_subtree_greater(r->right,r->data) && is_binary_tree(r->left) && is_binary_tree(r->right))
        return(1);
    else
        return 0;
}


int main(){
    
    
    BST *t1=new BST;BST *t2=new BST;BST *t3=new BST;BST *t4=new BST;BST *t5=new BST;
    t1->data=20;
    t2->data=10;
    t3->data=30;
    t4->data=5;
    t5->data=40;
    t1->left=t2;
    t1->right=t3;
    t3->left=t4;
    t3->right=t5;
     cout<<endl<<is_binary_tree(t1);
    
    
    
    ROOT=insert(ROOT,10);
    
    ROOT=insert(ROOT,5);
    ROOT=insert(ROOT,11);
    ROOT=insert(ROOT,7);
    ROOT=insert(ROOT,-1);
    
    cout<<endl<<is_binary_tree(ROOT);
    
    
}

    
