1
#include<iostream>
#include<queue>
using namespace std;

struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT=NULL;


BST *BST_from_preorder(int arr[],int l=0){
    if(l==0) return NULL;
    
    BST *root=new BST;
    root->data=arr[0];
    
    if(l==1) return(root);

    int i=0;
    while( i+1<l && arr[0]>arr[i+1] ){
        i++;
    }
    
    
    BST *le=BST_from_preorder(arr+1,i);
    BST *ri=BST_from_preorder(arr+i+1,l-(i+1));
    root->left=le;
    root->right=ri;

    
    return(root);
}

void D_F_S(BST *r){             // inorder traversal
    if(r==NULL) return;
    D_F_S(r->left);
    cout<<endl<<r->data;
    D_F_S(r->right);
}


int main(){
    
    int arr[]={10, 5, 1, 7, 40, 50};
    
    ROOT=BST_from_preorder(arr,6);

    D_F_S(ROOT);
}
