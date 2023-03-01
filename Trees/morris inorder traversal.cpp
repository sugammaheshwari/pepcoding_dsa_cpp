
// Morris Method for Tree Traversal
// best method for tree traversal without using stack or recurssion
// this method uses pointers and creates a thread for proper tree traversal
// Good Method !

#include<iostream>
#include<stack>

using namespace std;

struct node{
    int val;
    node *left=NULL;
    node *right=NULL;
};

node *insert(int x){
    node *t=new node();
    t->val=x;
    return t;
}

node *right_most_of_left_sub_tree(node *r,node *curr)
{
    node *t=r;
    while(t->right!=NULL && t->right!=curr)
        t=t->right;
    return t;
}


void morris_inorder_traversal(node *r){
    
    node * curr=r;
    
    while(curr!=NULL)
    {
        node *next_left=curr->left;
        
        if(next_left==NULL){
            cout<<endl<<curr->val;
            curr=curr->right;
            continue;                   // used to return to the looping condition.
        }
        
        node *right_most=right_most_of_left_sub_tree(next_left, curr);
        
        if(right_most->right==NULL){                 // create thread;

            right_most->right=curr;
            curr=curr->left;
        }
        else{             // break the previously created thread;

            right_most->right=NULL;
            cout<<endl<<curr->val;
            curr=curr->right;
            
        }
    }
}

int main(){
    
    node *root=insert(10);
    root->left=insert(20);
    root->right=insert(30);
    root->right->right=insert(40);
    root->left->left=insert(50);
    morris_inorder_traversal(root);
    cout<<"hello";
    
}
