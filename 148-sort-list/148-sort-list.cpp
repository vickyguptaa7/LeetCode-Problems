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

    ListNode* sortList(ListNode*&head) {
        if(!head||!head->next)return head;
        
        ListNode*mid=Midll(head);
      
        ListNode*first=head;
        ListNode*second=mid->next;
        
        mid->next=nullptr;
        
        first=sortList(first); 
        second=sortList(second);
        
        
        return merge(first,second);
    }
         
    ListNode*merge(ListNode*&first,ListNode*&second)
    {
        ListNode*newHead=nullptr;
        ListNode*iterator=nullptr;
        
        while(first&&second)
        {
            if(first->val<second->val)
            {
                if(newHead==nullptr)
                {
                    newHead=first;
                    iterator=first;
                    first=first->next;
                }
                else
                {
                    iterator->next=first;
                    iterator=iterator->next;
                    first=first->next;
                }
            }
            else
            {
                if(newHead==nullptr)
                {
                    newHead=second;
                    iterator=second;
                    second=second->next;
                }
                else
                {
                    iterator->next=second;
                    iterator=iterator->next;
                    second=second->next;
                }
            }
        }
        if(first)
        {
            iterator->next=first;
        }
        if(second)
        {
            iterator->next=second;
        }
        return newHead;
    }
    
    ListNode*Midll(ListNode*head)
    {
        if(!head||!head->next)return head;
        
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
};