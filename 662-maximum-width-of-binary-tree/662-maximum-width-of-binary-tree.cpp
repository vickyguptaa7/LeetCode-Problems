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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>que;
        que.push({root,0});
        long long result=0;
        while(!que.empty())
        {
            int size=que.size();
            long long Min=1e9,Max=0;
            long long leftMin=que.front().second;
            int k=0;
            while(k++<size)
            {
                TreeNode*curr=que.front().first;
                long long ind=que.front().second-leftMin;
                que.pop();
                if(k==1)Min=ind;
                if(k==size)Max=ind;
                if(curr->left)
                   que.push({curr->left,2*ind+1ll});
                if(curr->right)
                   que.push({curr->right,2*ind+2ll});
            }
            result=max(result,Max-Min+1);
        }
        return int(result);
    }
};