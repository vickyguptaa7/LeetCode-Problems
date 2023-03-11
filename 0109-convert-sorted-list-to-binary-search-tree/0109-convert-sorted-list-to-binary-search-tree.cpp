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
    ListNode* middleOfLinkedList(ListNode*head,ListNode*block)
    {   
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=block&&fast->next!=block)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head,ListNode*block=nullptr) {
        if(head==block)
            return nullptr;
        if(head->next==block)
            return new TreeNode(head->val);
        
        ListNode*mid=middleOfLinkedList(head,block);
        TreeNode*root=new TreeNode(mid->val);
        
        root->left=sortedListToBST(head,mid);
        root->right=sortedListToBST(mid->next,block);
        return root;
    }
};