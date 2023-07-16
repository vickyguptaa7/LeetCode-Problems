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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=dummy;
        while(curr&&curr->next)
        {
            int cntr=0;
            ListNode*temp=curr->next;
            while(temp&&temp->val==curr->next->val)
            {
                cntr++;
                temp=temp->next;
            }
            if(cntr>1)
            {
                curr->next=temp;
                continue;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};