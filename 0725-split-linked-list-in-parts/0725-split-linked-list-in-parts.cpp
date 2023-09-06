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
    
    int listLength(ListNode*head){
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=listLength(head);
        int rem=len%k;
        vector<ListNode*>res(k,nullptr);
        int take=len/k;
        for(int i=0;i<k;i++)
        {
            ListNode*curr=head;
            int cntr=take+(rem!=0);
            res[i]=head;
            while(--cntr>0)
            {
                curr=curr->next;
            }
            if(curr)
            {
                head=curr->next;
                curr->next=nullptr;                
            }
            if(rem>0)
                rem--;
        }
        return res;
    }
};