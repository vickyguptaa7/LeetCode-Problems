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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        int level=1;
        stack<int>st;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                if(!(level&1))
                {
                    curr->val=st.top();
                    st.pop();
                }
                if(curr->left)
                {
                    if(level&1)
                        st.push(curr->left->val);
                    que.push(curr->left);
                }
                if(curr->right)
                {
                    if(level&1)
                        st.push(curr->right->val);
                    que.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};