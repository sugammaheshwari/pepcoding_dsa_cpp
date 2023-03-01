

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



//function to display a vector

void vec_show(vector<node *> vec){
    
    if(vec.size()==0)
       return ;
       
    for(node *n:vec)
        cout<<n->val<<endl;
}

bool root_to_node_N_tree(node *r,int data,vector<node *> &path){
    
    if(r==NULL)
        return false;               // technically this case is not required as it is automatically handlled by res=false and return res statment!
    
    if(r->val==data){
        //display path vector as base case is reached! and whole path is stored in the path vector
        path.push_back(r);
        vec_show(path);
        return true;
    }
    
    path.push_back(r);
    bool res=false;
    for(node *n:r->children)
        res = res || root_to_node_N_tree(n, data, path);          // this || method prevents further calls as if res becomes true then recursion is simply not called !
    
    if(res==false)
        path.pop_back();
    
    return res;
    
}




int main(){

    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1};

    node *ROOT=create_N_Tree(arr);
    
   // cout<<"\n the tree created is :"<<endl;
   // display_n_tree(ROOT);
    
    vector<node*> vec;
    cout<<endl<<"the root to node path is "<<root_to_node_N_tree(ROOT,70,vec);


    

    
    
    
}
