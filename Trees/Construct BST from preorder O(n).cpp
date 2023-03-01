
// In place optimised method to generate BST from preorder traversal using Recurssion
// Time complexity : O(n)


BST* constr(int ub,int lb,int &idx,vector<int> &preorder)
{
       if(idx>=preorder.size() ) return NULL;
       TreeNode *r=new TreeNode(preorder[idx]);
       if( r->data<lb || r->data>ub) return NULL;
       
       idx++;
       if(idx>=preorder.size()) return r;
       
       r->left=constr(r->data,lb,idx,preorder);
       r->right=constr(ub,r->data,idx,preorder);
       
       return r;
}

