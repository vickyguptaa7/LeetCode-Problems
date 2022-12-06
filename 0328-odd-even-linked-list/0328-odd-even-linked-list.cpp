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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)
        {
            return head;
        }
        ListNode*even=head->next,*odd=head,*curr=head->next->next;
        ListNode*evenHead=head->next;
        even->next=nullptr;
        odd->next=nullptr;
        bool isOdd=true;
        while(curr)
        {
            if(isOdd)
            {
                odd->next=curr;
                curr=curr->next;
                odd=odd->next;
                odd->next=nullptr;
            }
            else
            {
                even->next=curr;
                curr=curr->next;
                even=even->next;
                even->next=nullptr;
            }
            isOdd=!isOdd;
        }
        odd->next=evenHead;
        return head;
    }
};