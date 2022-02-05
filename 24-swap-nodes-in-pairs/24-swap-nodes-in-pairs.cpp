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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode*odd=head,*even=head->next;
        ListNode*olist=head,*elist=head->next;
        while(odd&&even&&odd->next&&even->next)
        {
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=odd->next;
        }
        if(odd!=nullptr)
           odd->next=nullptr;
        if(even!=nullptr)
           even->next=nullptr;

        odd=olist;
        even=elist;
        ListNode*curr=even;
        even=even->next;
        int i=1;
        
        while(even&&odd)
        {
            if((i&1)==1)
            {
                curr->next=odd;
                odd=odd->next;
            }
            else
            {
                curr->next=even;
                even=even->next;
            }
            curr=curr->next;
            i++;
        }
        if(even)
        {
            curr->next=even;
        }
        if(odd)
        {
            curr->next=odd;
        }
        return elist;
    }
};