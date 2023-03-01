
/*
 
 LEET 863. All Nodes Distance K in Binary Tree
 We are given a binary tree (with root node root), a target node, and an integer value K.

 Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
 
 Example 1:

 Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

 Output: [7,4,1]

 Explanation:
 The nodes that are a distance 2 from the target node (with value 5)
 have values 7, 4, and 1.

 https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png       // image for question !!

 Note that the inputs "root" and "target" are actually TreeNodes.
 The descriptions of the inputs above are just serializations of these objects.
 
 
 */
class Solution {
public:
    
    vector<int> ans;
    
    void root_dis(TreeNode *r,int k)
    {
        if(!r || k<0)
            return;
        if(k==0)
            ans.push_back(r->val);
        root_dis(r->left,k-1);
        root_dis(r->right,k-1);
    }
    
    int find(TreeNode *r,TreeNode *t,int K)
    {
        if(!r || K<0 )  return -1;
        if(r==t)    {root_dis(r,K);return 1;}
        
        int d1=find(r->left,t,K);
        if(d1!=-1){
            r->left=NULL;
            root_dis(r,K-d1);
            return d1+1;
        }
        
        int d2=find(r->right,t,K);
        if(d2!=-1){
            r->right=NULL;
            root_dis(r,K-d2);
            return d2+1;
        }
        
        return -1;
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        find(root,target,K);
        return ans;
    }
};
