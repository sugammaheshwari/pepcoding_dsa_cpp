
#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left,*right;
    
    TreeNode(int x)
    {
        val=x;
        left=NULL;right=NULL;
    }
};


 void traverse(TreeNode *r,string &tree)
    {
        if(r==NULL){tree+="#";return;}
        tree+=to_string(r->val)+'X';
        traverse(r->left,tree);
        traverse(r->right,tree);
    }
    
string serialize(TreeNode* root)
    {
        string tree;
        traverse(root,tree);
        return tree;
    }


TreeNode *helper(string data,int &idx)
{
    if(idx>=data.length()) return NULL;
    if(data[idx]=='#') {idx++;return NULL;}
    
    string x;
    while(data[idx]!='X') x+=data[idx++];idx++;
    int x_=stoi(x);
    
    TreeNode *r=new TreeNode(x_);
    r->left=helper(data,idx);
    r->right=helper(data,idx);
    
    return r;
}

    TreeNode* deserialize(string data)
    {
        int idx=0;
        return helper(data,idx);
    }
    
    
void pre_order(TreeNode *r)
{
    if(r==NULL)
        return ;
    cout<<r->val<<":";
    pre_order(r->left);
    pre_order(r->right);
}
    

int main()
{
    TreeNode *root=new TreeNode(1);
    TreeNode *r1=new TreeNode(2);TreeNode *r2=new TreeNode(3);TreeNode *r3=new TreeNode(4);TreeNode *r4=new TreeNode(5);
    
    root->left=r1;root->right=r2;r2->left=r3;r2->right=r4;
    
    TreeNode *NEW_ROOT=deserialize(serialize(root));
    
    pre_order((NEW_ROOT));
    
}
