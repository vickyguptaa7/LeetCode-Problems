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
    map<int,int>omap; 
    int pathSum(TreeNode* root, int targetSum,long long sum=0) {

        if(!root)return 0;
        sum+=root->val;

        int paths=0;
        if(sum==targetSum)paths++;
        if(omap.count(sum-targetSum))
        {
            paths+=omap[sum-targetSum];
        }
        omap[sum]++;
        paths+=pathSum(root->left,targetSum,sum);
        paths+=pathSum(root->right,targetSum,sum);
        omap[sum]--;
        return paths;
    }
};