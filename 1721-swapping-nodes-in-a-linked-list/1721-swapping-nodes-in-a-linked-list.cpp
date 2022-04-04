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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*slow=head,*fast=head,*firstK=nullptr;
        k--;
        int temp=k;
        while(temp--)
        {
            fast=fast->next;
        }
        firstK=fast;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        temp=firstK->val;
        firstK->val=slow->val;
        slow->val=temp;
        return head;
    }
};