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
    
    ListNode*reverse(ListNode*head,ListNode*tail)
    {
        ListNode*prev=tail,*curr=head,*next=nullptr;
        while(curr!=tail)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*thead=dummy,*ttail=head;
        while(left>1)
        {
            left--;
            thead=thead->next;
        }
        while(right)
        {
            right--;
            ttail=ttail->next;
        }
        ListNode*rev=reverse(thead->next,ttail);
        thead->next=rev;
        return dummy->next;
        
    }
};