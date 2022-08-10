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
    
    TreeNode* helper(int strt,int end,vector<int>&nums)
    {
        if(strt>end)return nullptr;
        
        int mid=strt+(end-strt)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=helper(strt,mid-1,nums);
        root->right=helper(mid+1,end,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        
        return helper(0,n-1,nums);
    }
};