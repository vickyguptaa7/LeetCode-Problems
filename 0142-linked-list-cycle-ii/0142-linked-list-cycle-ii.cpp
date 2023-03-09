/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return nullptr;
        if(head->next==head)
            return head;
        
        ListNode*slow=head,*fast=head;
        do
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        while(fast&&fast->next);
        
        if(!fast||!fast->next)
            return nullptr;
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};