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
    TreeNode*helper(vector<int>& preorder, vector<int>& postorder,int &it1,int &it2)
    {
        TreeNode*newNode=new TreeNode(preorder[it1++]);
        if(newNode->val!=postorder[it2])
        newNode->left=helper(preorder,postorder,it1,it2);
        if(newNode->val!=postorder[it2])
        newNode->right=helper(preorder,postorder,it1,it2);
        it2++;
        return newNode;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int it1=0,it2=0;
        return helper(preorder,postorder,it1,it2);
    }
};