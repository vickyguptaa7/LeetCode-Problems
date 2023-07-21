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
    string findHashString(TreeNode*root,string& targetHash,bool& isFound)
    {
        if(!root)
            return "#";
        string left=findHashString(root->left,targetHash,isFound);
        string right=findHashString(root->right,targetHash,isFound);
        string curr=left+right+" "+to_string(root->val);
        
        if(!isFound&&curr==targetHash)
        {
            isFound=true;
        }
        return curr;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string targetHash="";
        bool isFound=false;
        targetHash=findHashString(subRoot,targetHash,isFound);
        isFound=false;
        findHashString(root,targetHash,isFound);
        return isFound;
    }
};