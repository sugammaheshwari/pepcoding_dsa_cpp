
// Root to node path for a binary tree
/* root to node path is function which dynamically finds the path from the root of the binary tree to
 the given node of integer value x.
 */

#include<iostream>
#include<vector>
using namespace std;


struct node{
    int val;
    node * left=NULL;
    node *right=NULL;
}*root;

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


bool has_path(node *r,vector<int> &arr,int x){
    
    if(r==NULL) return false;
    
    if( r->val==x) return true ;
    
    arr.push_back(r->val);
    
    if(r->val>x && has_path(r->left,arr,x)) return true ;
    
    if(r->val <x && has_path(r->right,arr,x) )  return true ;
       
    arr.pop_back();
    return false;
}


void display(vector<int> &arr, int vidx)

{
    if (vidx == arr.size())
        return;
    display(arr, vidx + 1);

    cout << arr[vidx] << " ";

}

int main(){
    
    root=insert_BST(root, 2);
    root=insert_BST(root, 7);
    root=insert_BST(root, -1);
    root=insert_BST(root, 5);
    root=insert_BST(root, 8);
    root=insert_BST(root, -3);
    
    vector<int> path;
    
    if(has_path(root, path, -3)){
        cout<<-3;
        display(path, 0);
    }

}
