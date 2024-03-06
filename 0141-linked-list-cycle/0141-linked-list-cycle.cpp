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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)return false;
        ListNode*slow=head,*fast=head;
        do{
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)break;
        }while(fast&&fast->next);
        return slow==fast;
    }
};