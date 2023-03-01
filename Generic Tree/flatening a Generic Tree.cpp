

// Genric Trees (N -array trees , trees having dynamic number of children )

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class node{
public:
    int val;
    vector<node*> children;
    
    node(int val){
        this->val=val;
    }
    
};


node * create_N_Tree(vector<int> &arr){
    
    stack<node *> st;
    node *root=NULL;
    
    for(int i=0;i<arr.size();i++){
        
        if(arr[i]!=-1){
            node *n=new node(arr[i]);
            if(i==0)
                root=n;
            st.push(n);
        }
        
        else{
            node *t=st.top();
            st.pop();
            st.top()->children.push_back(t);
        }
        
        
        
    }
    return root;
}


void display_n_tree(node *r){
    
    if(r==NULL)
        return;
    
    cout<<r->val<<":";
    
    for(node *n:r->children)
        cout<<n->val<<",";
    
    cout<<endl;
    
    for(node *n:r->children)
        display_n_tree(n);
    
    
}


void display_n_tree_modified(node *r){
    
    if(r==NULL)
        return;
    
    cout<<r->val<<":";
    
    for(node *n:r->children)
        cout<<n->val<<",";
    
}


void flattern(node *nodee)
{
    vector<node *> nchilds;
    for (node *n:nodee->children)
    {
        flattern(n);

        nchilds.push_back(n);
        for (node *child : n->children)
        {
            nchilds.push_back(child);
        }

        n->children.clear();
    }

    nodee->children.clear();
    nodee->children = nchilds;
}


int main(){

    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1};

    node *ROOT=create_N_Tree(arr);
    
    cout<<"\n the tree created is :"<<endl;
    display_n_tree(ROOT);
    
    cout<<endl<<"the tree after flatening is:";
    flattern(ROOT);
    display_n_tree_modified(ROOT);

    
    
 
    

    
    
    
}
