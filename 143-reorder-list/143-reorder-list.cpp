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
    void Display(ListNode*head)
    {
        ListNode*curr=head;
        while(curr)
        {
            cout<<curr->val<<" ";
            curr=curr->next;
        }
        cout<<"\n";
    }
    ListNode*reverse(ListNode*head)
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
    void reorderList(ListNode*head) {
        if(head==nullptr||head->next==nullptr)return;
        
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode*secondHalf=slow->next;
        secondHalf=reverse(secondHalf);
        slow->next=nullptr;
        ListNode*newList=nullptr;
        fast=head;
        newList=fast;
        fast=fast->next;
        while(fast&&secondHalf)
        {
            newList->next=secondHalf;
            secondHalf=secondHalf->next;
            newList=newList->next;
            newList->next=nullptr;
            newList->next=fast;
            fast=fast->next;
            newList=newList->next;
            newList->next=nullptr;
        }
        if(fast)
        {
            newList->next=fast;
        }
        if(secondHalf)
        {
            newList->next=secondHalf;
        }
    }
};