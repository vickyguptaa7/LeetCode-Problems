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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode*findMiddle(ListNode*head)
    {
        ListNode*slow=head,*fast=head->next;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        ListNode*middle=findMiddle(head);
        ListNode*right=reverseList(middle->next);
        middle->next=nullptr;
        ListNode*left=head->next,*curr=head;
        while(left&&right)
        {
            curr->next=right;
            right=right->next;
            curr=curr->next;
            curr->next=nullptr;
            if(left)
            {
                curr->next=left;
                left=left->next;
                curr=curr->next;
                curr->next=nullptr;
            }
        }
        if(right)
        {
           curr->next=right;
            right=right->next;
            curr=curr->next;
            curr->next=nullptr; 
        }
        
    }
};