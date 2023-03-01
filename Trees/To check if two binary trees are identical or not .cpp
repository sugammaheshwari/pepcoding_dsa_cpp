
// To check if two binary trees are identical or not
//simple question but good logic
// prouds

#include<iostream>
using namespace std;


struct node
{
    int data;
    node *left,*right;
};

bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL || r2==NULL)
        return false;
    if(r1->data!=r2->data)
        return false;
    return (isIdentical(r1->left,r2->left) &&
        isIdentical(r1->right,r2->right));
}
