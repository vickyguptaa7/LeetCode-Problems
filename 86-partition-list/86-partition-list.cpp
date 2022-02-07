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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||head->next==nullptr)
        return head;
    
        
        ListNode*h1=nullptr,*h2=nullptr;
        ListNode*pntr1=nullptr,*pntr2=nullptr;
        ListNode*curr=head;
        while(curr!=nullptr)
        {
            if(curr->val<x)
            {
                if(pntr1==nullptr)
                {
                    h1=curr;
                    pntr1=curr;
                }
                else
                {
                    pntr1->next=curr;
                    pntr1=pntr1->next;
                }
            }
            else
            {
                if(pntr2==nullptr)
                {
                    h2=curr;
                    pntr2=curr;
                }
                else
                {
                    pntr2->next=curr;
                    pntr2=pntr2->next;
                }
            }
            curr=curr->next;
        }
        if(pntr1)
        pntr1->next=h2;
        else return h2;
        if(pntr2)
        pntr2->next=nullptr;
        return h1;
    }
};