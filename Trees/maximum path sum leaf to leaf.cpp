
// IMP Question from interview prespective !
// To find the maximum path sum from leaf to leaf in a binary tree !!!!
//GEEKS : https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

int sum=INT_MIN;

int path_sum(node *r)
{
    if(r==NULL)
        return INT_MIN;
    int le=path_sum(r->left);
    int ri=path_sum(r->right);
    
    if(le!=INT_MIN && ri!=INT_MIN)
        sum=max(sum,le+ri+r->data);
    int x=max(le,ri);
    return x==INT_MIN?r->data:x+r->data;
}

int path_sum_final(node *root)
{
    if(root==NULL)
        return 0;
    path_sum(root);
    return sum;
}
