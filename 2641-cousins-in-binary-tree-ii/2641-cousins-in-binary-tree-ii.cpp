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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<pair<TreeNode*,TreeNode*>>que;
        que.push({root,nullptr});
        int psum=root->val;
        while(!que.empty())
        {
            int size=que.size();
            int sum=0;
            unordered_map<TreeNode*,int>childSum;
            queue<pair<TreeNode*,TreeNode*>>tempQue;
            while(size--)
            {
                auto curr=que.front();
                que.pop();
                tempQue.push(curr);
                sum+=curr.first->val;
                childSum[curr.second]+=curr.first->val;
                if(curr.first->left)
                {
                    que.push({curr.first->left,curr.first});
                }
                if(curr.first->right)
                {
                    que.push({curr.first->right,curr.first});
                }
            }
            size=tempQue.size();
            while(size--)
            {
                auto curr=tempQue.front();
                tempQue.pop();
                curr.first->val=sum-childSum[curr.second];
            }
        }
        return root;
    }
};