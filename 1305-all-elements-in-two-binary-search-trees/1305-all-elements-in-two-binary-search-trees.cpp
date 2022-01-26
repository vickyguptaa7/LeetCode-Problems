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
    vector<int>Sorted_Merge(vector<int>&tree1,vector<int>&tree2)
    {
        vector<int>result;
        int n=tree1.size(),m=tree2.size();
        int i=0,j=0;
        while(i<n&&j<m)
        {
            if(tree1[i]<tree2[j])
            {
                result.push_back(tree1[i]);
                i++;
            }
            else 
            {
                result.push_back(tree2[j]);
                j++;
            }
        }
        while(i<n)
        {
            result.push_back(tree1[i]);
            i++;
        }
        while(j<m)
        {
            result.push_back(tree2[j]);
            j++;
        }
        return result;
    }
    void Inorder(TreeNode*root,vector<int>&inorder)
    {
        if(root==nullptr)return;
        Inorder(root->left,inorder);
        inorder.push_back(root->val);
        Inorder(root->right,inorder);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1,tree2;
        Inorder(root1,tree1);
        Inorder(root2,tree2);
        vector<int>merge=Sorted_Merge(tree1,tree2);
        return merge;
    }
};