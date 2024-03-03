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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=dummy,*fast=dummy;
        while(n--)
        {
            fast=fast->next;
        }
        while(fast&&fast->next)
        {
            fast=fast->next;
            curr=curr->next;
        }
        if(curr&&curr->next)
            curr->next=curr->next->next;
        return dummy->next;
    }
};