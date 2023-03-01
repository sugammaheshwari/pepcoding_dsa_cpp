
#include<iostream>
#include<stack>
using namespace std;


class node
{
    public:
    int data;
    node* left, *right;
};
  
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
  
    return(Node);
}
  
// Traversal of a Binary Tree without using recurrsion ie : with STACK

void preoder(node *k){

    node *t=k;
    stack <node*> s;
    if(t==NULL) return ;
    
    while(t!=NULL){
    
        if(t->right!=NULL)
            s.push(t->right);
        
        if(t->left!=NULL){
            cout<<t->data<<endl;
            t=t->left;
        }
        else{
            cout<<t->data<<endl;
            if(!s.empty()){
                t=s.top();
                s.pop();
            }
            else
                break;
        }
            
    }
}


void inorder(node *r){
    
    stack <node*> s;
    node * curr=r;
    
    while(curr!=NULL || s.empty()==false){
        
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        
        curr=s.top();
        s.pop();
        
        cout<<curr->data<<endl;
        curr=curr->right;
    
    }
    
    
}

/* Driver code*/
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
  
    cout<<endl<<"the preoder traversal is :";
    preoder(root);

    cout<<endl<<"the inorder traversal is :";
    inorder(root);
    
    return 0;
}
