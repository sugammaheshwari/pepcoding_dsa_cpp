
// Program to serialise and Deserialise a binary Tree !!!
// GEEKS SOLUTION !!!!

#include<iostream>
using namespace std;
#include<vector>

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

vector<int> a;

void serial(node *r)
{
    if(r==NULL)
    {
        a.push_back(INT_MAX);
        return;
    }
    a.push_back(r->data);
    serial(r->left);
    serial(r->right);
}


node *de_Serial(int &idx)
{
    if(idx>=a.size())
        return NULL;
    if(a[idx]==INT_MAX)
    {
        idx++;
        return NULL;
    }
    node *x=new node(a[idx++]);
    x->left=de_Serial(idx);
    x->right=de_Serial(idx);
    
    return x;
}

void traverse(node *r)
{
    if(r==NULL)
        return;
    cout<<r->data;
    traverse(r->left);
    traverse(r->right);
}


int main()
{
    node *root=new node(1);
    node *n1=new node(2);
    node *n2=new node(3);
    node *n4=new node(4);
    
    root->left=n1;
    root->right=n2;
    root->right->right=n4;
    
    serial(root);
    
    int idx=0;
    node *new_root=de_Serial(idx);
    
    traverse(new_root);

}
