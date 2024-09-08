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
    
    int findLength(ListNode*head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>res;
        ListNode*curr=head;
        int cntr=0,total=findLength(head);
        while(k)
        {
            int len=ceil(total/(double)k);
            total-=len;
            res.push_back(curr);
            while(len)
            {
                if(len==1)
                {
                    ListNode*temp=curr->next;
                    curr->next=nullptr;
                    curr=temp;
                    break;
                }else{
                    curr=curr->next;
                }
                len--;
            }
            k--;
        }
        return res;
    }
};