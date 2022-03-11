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
    int length(ListNode*head)
    {
        int count=0;
        while(head)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        int len=length(head);
        if(k%len==0)
        {
            return head;
        }
        k%=len;
        ListNode*slow=head,*fast=head;
        while(k--)
        {
            fast=fast->next;
        }
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};