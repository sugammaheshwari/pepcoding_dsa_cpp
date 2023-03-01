
// inorder Traversal & preorder Traversal of Binary Tree without using Recursion
// Stack was used to solve the above problem 1

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

stack<Node *> st;

void inorder(Node *r)
{
    while(1)
    {
        while(r!=NULL)
        {
            st.push(r);
            r=r->left;
        }
        
        if(st.empty())
            break;
        
        r=st.top(); st.pop();
        cout<<r->data<<":";
        r=r->right;
    }

}

void preorder(Node *r)
{
    stack<Node *> st;
    
    while(1)
    {
        while(r!=NULL)
        {
            cout<<r->data<<":";
            st.push(r);
            r=r->left;
        }
        
        if(st.empty())
            break;
        
        r=st.top();
        st.pop();
        r=r->right;
    }
}


void inorder_2(Node *r)
{
    if(r==NULL)
        return ;
    inorder_2(r->left);
    cout<<r->data<<":";
    inorder_2(r->right);
}

int main()
{
        struct Node *root = new Node(1);
        root->left             = new Node(2);
        root->right         = new Node(3);
        root->left->left     = new Node(4);
        root->left->right = new Node(5);
        inorder(root);

    //    inorder_2(root);
}

