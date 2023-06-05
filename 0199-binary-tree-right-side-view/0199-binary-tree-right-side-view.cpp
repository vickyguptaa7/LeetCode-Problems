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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int>rightViewNodes;
        queue<TreeNode*>que;
        que.push(root);
        while(que.size())
        {
            int size=que.size();
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
                if(size==0)
                    rightViewNodes.push_back(curr->val);
            }
        }
        return rightViewNodes;
    }
};