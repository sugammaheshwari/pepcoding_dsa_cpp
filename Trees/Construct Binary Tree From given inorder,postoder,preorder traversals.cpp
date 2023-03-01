
// LEETCODE : 105 CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL !

class Solution1 {
public:
    
    unordered_map<int,int> mp;
    int idx;
    
    TreeNode *construct(vector<int>& preorder, vector<int>& inorder,int lb,int ub)
    {
        if(lb>ub) return NULL;
        TreeNode *r=new TreeNode(preorder[idx++]);
        if(lb==ub) return r;
        
        int mid=mp[r->val];
        r->left=construct(preorder,inorder,lb,mid-1);
        r->right=construct(preorder,inorder,mid+1,ub);
        
        return r;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        mp.clear();
        idx=0;
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        return construct(preorder,inorder,0,inorder.size()-1);
    }
};

// LEETCODE : 106 CONSTRUCT BINARY TREE FROM INORDER AND POSTORDER TRAVERSAL

class Solution2 {
public:
    
    unordered_map<int,int> mp;
    int idx;
    
    TreeNode *Construct(vector<int>& inorder, vector<int>& postorder,int lb,int ub)
    {
        if(lb>ub) return NULL;
        TreeNode *r=new TreeNode(postorder[idx--]);
        if(lb==ub) return r;
        
        int mid=mp[r->val];
        r->right=Construct(inorder,postorder,mid+1,ub);
        r->left=Construct(inorder,postorder,lb,mid-1);
        
        return r;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        mp.clear();
        idx=inorder.size()-1;
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        return Construct(inorder,postorder,0,inorder.size()-1);
    }
};

// LEETCODE : 889 CONSTRUCT BINARY TREE FROM PREORDER AND POSTORDER TRAVERAL
/*
 when pre and post are given to constuct the binary tree then the tree given should be
 full binary tree ( ie 0/2 children ) for the problem to be a valid one !
 */


class Solution {
public:
    
    unordered_map<int,int> mp;
    int idx=0;
    
    TreeNode *make(vector<int>& pre, vector<int>& post,int l,int u)
    {
        if(l>u) return NULL;
        TreeNode *r=new TreeNode(pre[idx++]);
        if(l==u) return r;
        int m=mp[pre[idx]];
        r->left=make(pre,post,l,m);
        r->right=make(pre,post,m+1,u-1);
        
        return r;
    }
    
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
        mp.clear();
        idx=0;
        
        for(int i=0;i<post.size();i++)
            mp[post[i]]=i;
        
        return make(pre,post,0,pre.size()-1);
    }
};


/*
 
 IMPORTANT THING TO REVISE
 
 The main differnce between LEET 105 and LEET 889 is that
 
 in 889 - > we search for the index of next element MAP[pre[curr_idx+1]] from our stored hash map
 in 105 - > we searcg fir the index of curr element by using MAP[r->val] from our stored hash map !!
 
 */
