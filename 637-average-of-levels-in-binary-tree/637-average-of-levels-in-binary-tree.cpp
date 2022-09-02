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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        vector<double>res;
        while(!que.empty())
        {
            int size=que.size(),noOfEle=que.size();
            double sum=0;
            while(size--)
            {
                auto curr=que.front();
                que.pop();
                sum+=curr->val;
                if(curr->left)que.push(curr->left);
                if(curr->right)que.push(curr->right);
            }
            sum/=noOfEle;
            res.push_back(sum);
        }
        return res;
    }
};