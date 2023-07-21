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
        if(strt==end)
            return new TreeNode(nums[strt]);
        if(strt>end)
            return nullptr;
        int mid=strt+(end-strt)/2;
        TreeNode*curr=new TreeNode(nums[mid]);
        curr->left=helper(strt,mid-1,nums);
        curr->right=helper(mid+1,end,nums);
        return curr;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
    }
};