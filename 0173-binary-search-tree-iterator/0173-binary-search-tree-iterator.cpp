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
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushLeftChilds(root);
    }
    
    int next() {
        TreeNode*curr=st.top();
        st.pop();
        int val=curr->val;
        curr=curr->right;
        pushLeftChilds(curr);
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushLeftChilds(TreeNode*root)
    {
        if(!root)
            return;
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */