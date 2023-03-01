/*
Given a Binary Tree, find the diagnol sum of the nodes that are in the same diagnal line.
Print all sums.
*/

#include<iostream>
#include<map>

using namespace std;
  
struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void diagnol_sum(Node *r,int lvl,map <int,int> &map1){
    
    
    if(r==NULL) return;
    
    diagnol_sum(r->left, lvl+1, map1);
    map1[lvl]+=r->data;
    diagnol_sum(r->right, lvl+0, map1);
    
}

void call_sum(Node *r){
    
    map <int ,int> map1;
    map<int ,int> ::iterator itr;
    
    diagnol_sum(r, 0, map1);
    
    for(itr=map1.begin();itr!=map1.end();itr++){
        cout<<"diagnol"<<itr->first<<":"<<itr->second<<endl;
    }
    
}




int main()
{
     Node* root = newNode(1);
       root->left = newNode(2);
       root->right = newNode(3);
       root->left->left = newNode(9);
       root->left->right = newNode(6);
       root->right->left = newNode(4);
       root->right->right = newNode(5);
       root->right->left->right = newNode(7);
       root->right->left->left = newNode(12);
       root->left->right->left = newNode(11);
       root->left->left->right = newNode(10);
  
    call_sum(root);
  
    return 0;
}
