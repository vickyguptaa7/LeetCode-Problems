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
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> post;
    if (root == nullptr)
        return post;
    stack<TreeNode *> node_st;
    node_st.push(root);
    TreeNode *curr = nullptr;
    while (!node_st.empty())
    {
        curr = node_st.top();
        node_st.pop();
        post.push_back(curr->val);

        if (curr->left)
        {
            node_st.push(curr->left);
        }
        if (curr->right)
        {
            node_st.push(curr->right);
        }
    }
    reverse(post.begin(), post.end());
    return post;
    }
};