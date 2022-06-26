class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }
        //Step1: 
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;
        
        ListNode* itr=curr;
        while(itr!=nullptr&&count<k)
        {
            count++;
            itr=itr->next;
        }
        
        if(count==k)
        while(curr!=NULL && count>0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        else
            return head;
        
        //Step2: 
        if(next != NULL)
        {
            head->next = reverseKGroup(next,k);
        }
        
        return prev;
    }
};