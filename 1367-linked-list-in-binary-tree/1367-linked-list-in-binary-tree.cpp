/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    bool helper(TreeNode*root,ListNode*curr)
    {
        if(!curr)
            return true;
        if(!root)
            return false;

        if(curr->val==root->val)
        {
            if(helper(root->left,curr->next))
                return true;
            if(helper(root->right,curr->next))
                return true;
        }
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        
        return isSubPath(head,root->left)|isSubPath(head,root->right)|(helper(root,head));
    }
};