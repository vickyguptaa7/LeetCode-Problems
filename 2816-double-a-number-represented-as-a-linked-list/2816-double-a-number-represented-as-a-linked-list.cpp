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
    
    ListNode*reverseList(ListNode*head)
    {
        ListNode*curr=head,*prev=nullptr,*next=nullptr;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode*curr=reverseList(head);
        head=curr;
        int rem=0;
        while(curr)
        {
            curr->val*=2;
            int val=rem;
            val+=curr->val%10;
            rem=curr->val/10;
            curr->val=val;
            curr=curr->next;
        }
        head=reverseList(head);
        if(rem)
        {
            ListNode*dummy=new ListNode(1);
            dummy->next=head;
            head=dummy;
        }
        return head;
    }
};