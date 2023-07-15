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
    ListNode*reverseLinkedList(ListNode*head)
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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode*middle=findMiddle(head);
        ListNode*rightList=reverseLinkedList(middle->next);
        ListNode*leftList=head;
        middle->next=nullptr;
        while(rightList)
        {
            if(rightList->val!=leftList->val)
            {
                return false;
            }
            rightList=rightList->next;
            leftList=leftList->next;
        }
        
        return true;
    }
};