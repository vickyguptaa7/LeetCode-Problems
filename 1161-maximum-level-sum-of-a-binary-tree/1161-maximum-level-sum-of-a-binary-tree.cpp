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
    int maxLevelSum(TreeNode* root) {
        int mxLvl=1,lvl=1,mxSum=-2e9;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            int sum=0;
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                sum+=curr->val;
                if(curr->left)que.push(curr->left);
                if(curr->right)que.push(curr->right);
            }
            if(mxSum<sum)
            {
                mxLvl=lvl;
                mxSum=sum;
            }
            lvl++;
        }
        return mxLvl;
    }
};