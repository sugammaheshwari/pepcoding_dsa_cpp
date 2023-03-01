
#include<iostream>
#include<stack>

using namespace std;

struct node{
    int val;
    node *left=NULL;
    node *right=NULL;
    bool ld=false;
    bool rd=false;
    bool sd=false;
};


node *newNode(int x){
    
    node *t=new node();
    t->val=x;
    
    return (t);
}


void postorder_traverse(node * r){
    
    stack <node *> s;
    s.push(r);
    
    while(!s.empty()){
        node *curr=s.top();
        
        if(!curr->ld){
            curr->ld=true;
            if(curr->left!=NULL)
                s.push(curr->left);
        }
        else if(!curr->rd){
            curr->rd=true;
            if(curr->right!=NULL)
                s.push(curr->right);
        }
        else if(!curr->sd){
            curr->sd=true;
            cout<<endl<<curr->val;
        }
        else
            s.pop();
    
    }
}

void inorder_traverse(node * r){
    
    stack <node *> s;
    s.push(r);
    
    while(!s.empty()){
        node *curr=s.top();
        
        if(!curr->ld){
            curr->ld=true;
            if(curr->left!=NULL)
                s.push(curr->left);
        }
        
        else if(!curr->sd){
            curr->sd=true;
            cout<<endl<<curr->val;
        }

        else if(!curr->rd){
            curr->rd=true;
            if(curr->right!=NULL)
                s.push(curr->right);
        }
        else
            s.pop();
    
    }
}

void preorder_traverse(node * r){
    
    stack <node *> s;
    s.push(r);
    
    while(!s.empty()){
        node *curr=s.top();
        
        if(!curr->sd){
            curr->sd=true;
            cout<<endl<<curr->val;
        }
        else if(!curr->ld){
            curr->ld=true;
            if(curr->left!=NULL)
                s.push(curr->left);
        }
        else if(!curr->rd){
            curr->rd=true;
            if(curr->right!=NULL)
                s.push(curr->right);
        }
        else
            s.pop();
    
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
    
    cout<<endl<<"traversal is:";
    preorder9_traverse(root);
}
