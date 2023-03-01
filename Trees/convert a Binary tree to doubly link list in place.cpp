
// Program to convert binary tree to a doubly link list in place
// ie without using extra memory !!!

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    
    node(int x)
    {
        data=x;
        left=NULL;right=NULL;
    }
};

void convert(node *r)
{
    if(r==NULL)
        return;
    
    if(r->left!=NULL)
    {
        convert(r->left);
        node *t=r->left;
        while(t->right!=NULL)
            t=t->right;
        t->right=r;
        r->left=t;
    }
    
    if(r->right!=NULL)
    {
        convert(r->right);
        node *t=r->right;
        while(t->left!=NULL)
            t=t->left;
        t->left=r;
        r->right=t;
    }
}


