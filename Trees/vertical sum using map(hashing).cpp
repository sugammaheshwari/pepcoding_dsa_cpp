/*
Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line.
Print all sums through different vertical lines.

       1
     /   \
   2      3
  / \    / \
 4   5  6   7

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
 
 */

// solution using Map , easy implementation

#include<iostream>
#include<map>

using namespace std;
  
struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


void vertical_Sum(Node *r, int lvl,map<int, int> &Map) {

    if(r==NULL) return;
    
    vertical_Sum(r->left, lvl-1, Map);
    Map[lvl]+=r->data;
    vertical_Sum(r->right,lvl+1,Map);

}

void cal_sum(Node *r){
    
    map <int,int> Map;
    map <int,int> :: iterator itr;

    vertical_Sum(r,0,Map);
    
    for(itr=Map.begin();itr!=Map.end();itr++)
        cout<<itr->first<<" : "<<itr->second<<endl;

    
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
  
    cal_sum(root);
  
    return 0;
}
