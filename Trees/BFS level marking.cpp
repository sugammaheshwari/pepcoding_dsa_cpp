
// marking level of nodes of BST using BFS 

#include<iostream>
#include<queue>

using namespace std;
struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
    int lvl=-1;
}*ROOT=NULL;


void breath_F_S(BST *r){
    queue<BST*> q;
    
    if(r==NULL){
        cout<<"\n empty tree";
        return;
    }
    int level=0;
    r->lvl=level;
    q.push(r);
    
    while(!q.empty()){
        if(q.front()->left!=NULL){
            q.front()->left->lvl=q.front()->lvl+1;
            q.push(q.front()->left);
        }
        if (q.front()->right!=NULL){
            q.front()->right->lvl=q.front()->lvl+1;
            q.push(q.front()->right);
        }
        
        cout<<endl<<q.front()->data<<"lvl:" <<q.front()->lvl;
        q.pop();
    }
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
    
    breath_F_S(ROOT);
    
}




