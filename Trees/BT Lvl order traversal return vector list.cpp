
/* LEET code problem 102
 
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 For example:
 Given binary tree [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 return its level order traversal as:

 [
   [3],
   [9,20],
   [15,7]
 ]

 */


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
    
    vector<vector<int>> list;
    

    void _levelOrder(TreeNode* root, int level) {
           if (root == NULL)
               return;
           
            if (level >= list.size())
                list.push_back(*(new vector<int>()));
           
           _levelOrder(root->left, level + 1);
           list[level].push_back(root->val);
           _levelOrder(root->right, level + 1);
       }



    vector<vector<int>> levelOrder(TreeNode* root) {
        _levelOrder(root, 0);
        return list;
    }
    


};
