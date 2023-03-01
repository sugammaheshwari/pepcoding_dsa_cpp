
//given inorder traversal of a BST , two elements are not in their correct posistion
// find them and recover the BST .

#include<iostream>
using namespace std;

struct BST{
    int data;
    BST *left;
    BST *right;
}*ROOT=NULL;

//  METHOD 1 Without Using Recursion
void  find_wrong_placed_elements(){
    int arr[]={10,20,80,70,30,90};
    
    int x=-1,y=-1;          // uninitiallised types
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            if(x==-1){
            x=arr[i];
            y=arr[i];
        }
            else{
                y=arr[i+1];
            }
      }
    }

    cout<<endl<<"the elements are:"<<x<<endl<<y;
}

//Method 2 Recurrsive Solutions

BST *x=NULL,*y=NULL,*z=NULL;

bool recover_BST(BST *r){
    if(r==NULL) return false;
    
    bool res=false;
    res=res|| recover_BST(r->left);
    
    if(z!=NULL && r->data<z->data){
        y=r;
        if(x==NULL) x=z;
        else return true;
        
    }
    
    z=r;
    res=res||recover_BST(r->right);
    return(res);
}
