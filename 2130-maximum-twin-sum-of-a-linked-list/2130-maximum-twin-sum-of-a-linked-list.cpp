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
    ListNode* Reverse(ListNode*head)
    {
        if(head==nullptr||head->next==nullptr)return head;
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
    ListNode*Middle(ListNode*head)
    {
        ListNode*slow=head,*fast=head->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode*mid=Middle(head);
        ListNode*reversed=Reverse(mid->next);
        mid->next=nullptr;
        int max_sum=0;
        while(reversed)
        {
            int sum=head->val+reversed->val;
            max_sum=max(max_sum,sum);
            head=head->next;
            reversed=reversed->next;
        }
        return max_sum;
    }
};