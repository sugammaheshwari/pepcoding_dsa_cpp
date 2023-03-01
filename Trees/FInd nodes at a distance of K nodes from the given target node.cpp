/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> ans;
    
    void find_k_dis_from_root(TreeNode *r,int k)
    {
        if(!r || k<0) return;
        if(k==0) ans.push_back(r->val);
        find_k_dis_from_root(r->left,k-1);
        find_k_dis_from_root(r->right,k-1);
    }
    
  
    int traverse(TreeNode *r,TreeNode *t,int k)
    {
        if(!r) return -1;
        if(r==t)
        {
            find_k_dis_from_root(r,k);
            return 1;
        }
        
        int d1=traverse(r->left,t,k);
        if(d1!=-1)
        {
            if(k==d1)
            {
                ans.push_back(r->val);
                return -1;
            }
            find_k_dis_from_root(r->right,k-1-d1);
            return d1+1;
        }
        
        int d2=traverse(r->right,t,k);
        if(d2!=-1)
        {
            if(k==d2)
            {
                ans.push_back(r->val);
                return -1;
            }
            find_k_dis_from_root(r->left,k-1-d2);
            return d2+1;
        }
        
        return -1;
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        int t=traverse(root,target,K);
        return ans;
    }
};
