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
        if(head==nullptr)return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*small=nullptr,*sitr=nullptr,*itr=dummy;
        
        while(itr&&itr->next)
        {
            if(itr->next->val<x)
            {
                if(small==nullptr)
                {
                    small=itr->next;
                    sitr=itr->next;
                    itr->next=itr->next->next;
                }
                else
                {
                    sitr->next=itr->next;
                    sitr=sitr->next;
                    itr->next=itr->next->next;
                }
            }
            else
              itr=itr->next;
        }
        if(sitr==nullptr)return dummy->next;
        
        sitr->next=dummy->next;
        return small;
    }
};