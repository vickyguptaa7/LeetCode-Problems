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
    
    int helper(vector<int>&arr)
    {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]];
        }
        int cnt=0;
        for(auto &x:mp)
        {
            x.second=cnt++;
        }
        map<int,vector<int>>list;
        int ans=0;
        vector<int>visit(arr.size(),0);
        for(int i=0;i<arr.size();i++)
        {
            if(visit[i])continue;
            int count=0;
            int curr=i;
            do
            {
                visit[curr]=true;
                count++;
                curr=mp[arr[curr]];
            }while(curr!=i);
            ans+=count-1;
        }
        return ans;
    }
    
    int minimumOperations(TreeNode* root) {
        int mnOper=0;
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty())
        {
            int size=que.size();
            vector<int>temp;
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            mnOper+=helper(temp);
        }
        
        return mnOper;
    }
};