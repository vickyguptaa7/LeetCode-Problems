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
    unordered_map<long long,int>mmp;
    int pathSum(TreeNode* root, int targetSum,long long currSum=0) {
        if(!root)return 0;
        currSum+=root->val;
        int paths=0;
        if(currSum==targetSum)paths++;
        if(mmp.count(currSum-targetSum))paths+=mmp[currSum-targetSum];
        mmp[currSum]++;
        paths+=pathSum(root->left,targetSum,currSum);
        paths+=pathSum(root->right,targetSum,currSum);
        mmp[currSum]--;
        return paths;
    }
};