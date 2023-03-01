
// BFS of a BST using queue

#include<iostream>
#include<queue>

using namespace std;
struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT=NULL;

void breath_F_S(BST *r){
    queue<BST*> q;
    
    if(r==NULL){
        cout<<"\n empty tree";
        return;
    }
    q.push(r);
    while(!q.empty()){
        if(q.front()->left!=NULL) q.push(q.front()->left);
        if (q.front()->right!=NULL) q.push(q.front()->right);
        cout<<endl<<q.front()->data;
        q.pop();
    }
    
}


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

int main(){
    ROOT=insert(ROOT, 10);
    ROOT=insert(ROOT,5);
    ROOT=insert(ROOT, 7);
    ROOT=insert(ROOT,4);
    ROOT=insert(ROOT, 112);
    ROOT=insert(ROOT,-5);
    
    //breath_F_S(ROOT);
    D_F_S(ROOT);
}

// code for level order traversal of a binary tree




