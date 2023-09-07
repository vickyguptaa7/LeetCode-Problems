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
    
    ListNode* reverseList(ListNode*head)
    {
        ListNode*prev=nullptr,*curr=head,*next=nullptr;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
public:
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=dummy;
        ListNode*leftptr=nullptr,*rightptr=nullptr;
        left--;
        while(left)
        {
            left--;
            right--;
            curr=curr->next;
        }
        leftptr=curr;
        while(right)
        {
            right--;
            curr=curr->next;
        }
        rightptr=curr;
        curr=curr->next;
        rightptr->next=nullptr;
        ListNode*nhead=reverseList(leftptr->next);
        leftptr->next=nhead;
        while(nhead&&nhead->next)
        {
            nhead=nhead->next;
        }
        nhead->next=curr;
        return dummy->next;
    }
};