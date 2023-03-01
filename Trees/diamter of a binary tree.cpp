
// to find diamter of binary tree
// dry run the example : https://www.geeksforgeeks.org/diameter-of-a-binary-tree/


#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

int g_dia=0;

int dia(node *r)
{
    if(r==NULL)
        return 0;
    int left_d=dia(r->left);
    int right_d=dia(r->right);
    g_dia=max(g_dia,left_d+right_d+1);
    
    return max(left_d,right_d)+1;
}

int diameter(node *root)
{
    if(root==NULL)
        return 0;
    dia(root);
    return g_dia-1;
}
