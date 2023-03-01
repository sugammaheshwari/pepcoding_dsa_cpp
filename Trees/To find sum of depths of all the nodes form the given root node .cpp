
//TO FIND :  the sum of depths all the nodes  of given root node

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int val;
    node *left,*right;
    
    node(int x)
    {
        val=x;
        left=right=NULL;
    }
    
};

// returns depth sum and no of nodes respectively
pair<int,int> find(node *r)
{
    pair<int,int> p=make_pair(0,1);
    
    if(r->left)
    {
        pair<int,int> child=find(r->left);
        p.second+=child.second;
        p.first+=child.first+child.second;
    }
    
    if(r->right)
    {
        pair<int,int> child=find(r->right);
        p.second+=child.second;
        p.first+=child.first+child.second;
    }
    
    return p;
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
    
    pair<int,int> p=find(root);
    cout<<p.first<<":"<<p.second<<endl;
}
