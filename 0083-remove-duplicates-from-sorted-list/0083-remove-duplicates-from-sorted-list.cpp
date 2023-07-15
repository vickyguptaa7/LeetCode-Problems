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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head;
        while(curr)
        {
            ListNode*next=curr->next;
            while(next&&curr->val==next->val)
            {
                next=next->next;
            }
            curr->next=next;
            curr=curr->next;
        }
        return head;
    }
};