/*
 
Problem Statement : Maximum Consecutive Increasing Path Length in Binary Tree

Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order. Every node is considered as a path of length 1.
Examples:

       10
      /    \
     /      \
    11        9
   / \        /\
  /   \      /  \
13    12    13   8
Maximum Consecutive Path Length is 3 (10, 11, 12)
Note: 10, 9 ,8 is NOT considered since
the nodes should be in increasing order.

            5
          /  \
         /    \
        8      11
        /        \
       /          \
       9             10
      /              /
     /             /
    6           15
Maximum Consecutive Path Length is 2 (8, 9).
 */

#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    Node *left, *right;
    int val;
}*root=NULL;
  
Node *newNode(int val)
{
    Node *temp = new Node();
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

int len=0;

void longest_sequence(Node * r, int x,int cur_len){
 
    if(r==NULL) return;
    
    if(r->val==x)
        cur_len++;
    else
        cur_len=1;
    
    len=max(cur_len,len);
    longest_sequence(r->left,r->val+1,cur_len);
    longest_sequence(r->right,r->val+1,cur_len);

}

// driver program

    int main()
    {
        root = newNode(10);
        root->left = newNode(11);
        root->right = newNode(9);
        root->left->left = newNode(13);
        root->left->right = newNode(12);
        root->right->left = newNode(13);
        root->right->right = newNode(8);
      
        longest_sequence(root,10,0);
        cout << "Maximum Consecutive Increasing Path Length is  :" <<len<<endl;
    
        return 0;
    }
    
    

