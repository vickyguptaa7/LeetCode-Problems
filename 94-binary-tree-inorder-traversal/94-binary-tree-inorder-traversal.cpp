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

    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> in;
    if (root == nullptr)
        return in;
    stack<TreeNode *> node_st;
    TreeNode *curr = root;
    while (true)
    {
        if (curr)
        {
            node_st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (node_st.empty())
                break;
            curr = node_st.top();
            in.push_back(curr->val);
            node_st.pop();
            curr = curr->right;
        }
    }
    return in;
    }
};