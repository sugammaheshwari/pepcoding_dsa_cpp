
// optimised program to find diameter of BST in O(n) time

#include<iostream>
#include<cmath>
using namespace std;

struct BST{
    int data;
    BST *left=NULL;
    BST *right=NULL;
}*ROOT=NULL;

int global_dia=-1;

int find_dia_BST(BST *r){
    if(r==NULL) return 0;
    
    int ld=find_dia_BST(r->left);
    int rd=find_dia_BST(r->right);
    
    global_dia=max(global_dia,ld+rd+1);
    return(max(ld,rd)+1);
}

int main(){
    
}
