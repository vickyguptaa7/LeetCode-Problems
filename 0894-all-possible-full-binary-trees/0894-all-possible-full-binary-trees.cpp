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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n&1))
            return {};
        
        if(n==1)
            return {new TreeNode(0)};
        
        vector<TreeNode*>list;
        
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*>left=allPossibleFBT(i);
            vector<TreeNode*>right=allPossibleFBT(n-i-1);
            
            for(auto lnode:left)
            {
                for(auto rnode:right)
                {
                    list.push_back(new TreeNode(0,lnode,rnode));
                }
            }
        }
        return list;
    }
};