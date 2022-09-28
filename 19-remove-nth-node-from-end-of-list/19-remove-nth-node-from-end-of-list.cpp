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
        if(!head->next)return nullptr;
        
        ListNode*fast=head;
        while(n>1)
        {
            fast=fast->next;
            n--;
        }
        if(fast->next==nullptr)return head->next;
        ListNode*prev=head,*curr=head;
        while(fast->next)
        {
            fast=fast->next;
            if(prev!=curr)prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};