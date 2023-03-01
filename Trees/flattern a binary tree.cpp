

/* Program to flatten a given Binary
Tree into linked list

basically there as two methods to do the same
 
 method 1: without using auxilary space (Extra space)
 method 2: using stack (ie extra space )
 */

#include <iostream>
#include<stack>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};


Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}


void flattern_M01(Node *r){
    
    if(r==NULL || ( r->left==NULL && r->right==NULL ) )          //r==NULL to check the base case if NULL tree this main tree null condition can be also checked before                                                                     making a call to the flattern_M01 function.
        return;
    
    if(r->left!=NULL){
        flattern_M01(r->left);          // ie traversing left recursively till the second last node;
        
        Node *temp=r->right;        // string current root's right
        r->right=r->left;
        r->left=NULL;
        
        Node *t=r->right;
        while(t->right!=NULL)
            t=t->right;
        
        t->right=temp;
    }
    
    flattern_M01(r->right);
    
}


void flattern_M02(Node *r){
    
    if(r==NULL) return;
    stack <Node*> st;
    st.push(r);
    
    while(!st.empty()){
        
        Node *curr=st.top();
        st.pop();
        
        if(curr->right!=NULL)
            st.push(curr->right);
        
        if(curr->left!=NULL)
            st.push(curr->left);
        
        if(!st.empty())
            curr->right=st.top();
        
    curr->left=NULL;
    }
    
}


void print_tree_inorder(Node* root)
{
    // base condition
    if (root == NULL)
        return;
    print_tree_inorder(root->left);
    cout << root->key << " ";
    print_tree_inorder(root->right);
}

int main()
{
   
    /*      1
            / \
           2    5
          / \     \
        3    4     6
     
    */
    
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    cout << "The Inorder traversal before flattening binary tree ";
    print_tree_inorder(root);

    flattern_M01(root);
    cout << "The Inorder traversal after flattening binary tree ";
    print_tree_inorder(root);


}

