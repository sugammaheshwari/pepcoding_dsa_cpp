

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

// the below function checks if the tree is mirror ie if left side overlapps the right side of the tree
// in below function we check and return false for all the false cases and if all pass then by default we return true !

bool is_Mirror_generic_tree(node *r1,node *r2){
    
    if(r1->children.size()!=r2->children.size() && r1->val!=r2->val)
        return false;
    
    for(int i=0,j=int(r1->children.size())-1; i<=j; i++,j--){
        
        bool res=is_Mirror_generic_tree(r1->children[i], r2->children[j]);
        if(res==false)
            return false;
    }
    
    return true;
}

int main(){

    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1};

    node *ROOT=create_N_Tree(arr);
    
   // cout<<"\n the tree created is :"<<endl;
   // display_n_tree(ROOT);
    
    vector<node*> vec;


    

    
    
    
}
