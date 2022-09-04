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
typedef pair<TreeNode*,int> ppi;
bool mycomp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<ppi>que;
        que.push({root,0}); // x <->    y |
        map<int,vector<pair<int,int>>>verNodes;
        int y=0;
        while(!que.empty())
        {
            int size=que.size();
            y++;
            while(size--)
            {
            auto curr=que.front();
            que.pop();
            verNodes[curr.second].push_back({curr.first->val,y});
            if(curr.first->left)
            {
                que.push({curr.first->left,curr.second-1});
            }
            if(curr.first->right)
            {
                que.push({curr.first->right,curr.second+1});
            }
            }
        }
        vector<vector<int>>result;
        for(auto &x:verNodes)
        {
            sort(x.second.begin(),x.second.end(),mycomp);
            vector<int>row;
            for(auto y:x.second)
            {
                row.push_back(y.first);
            }
            result.push_back(row);
        }
        return result;
    }
};