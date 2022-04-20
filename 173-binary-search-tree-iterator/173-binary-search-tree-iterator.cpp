/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode*curr;
    int val;
    public:

    BSTIterator(TreeNode* root) {
        curr=root;
        val=-1;
    }
    void helper(TreeNode*root,int val,int &tar)
    {
        if(!root)return;
        if(root->val>val)
        {
            tar=root->val;
            helper(root->left,val,tar);
        }
        else
        {
            helper(root->right,val,tar);
        }
    }
    int next() {
        int tar=-1;
       helper(curr,val,tar);
        val=tar;
        return tar;
    }
    
    bool hasNext() {
        int tar=-1;
        helper(curr,val,tar);
        if(tar==-1)return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */