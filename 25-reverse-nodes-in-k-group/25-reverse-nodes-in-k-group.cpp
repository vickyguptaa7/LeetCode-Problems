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
    int Count_Nodes(ListNode*head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=Count_Nodes(head);
        if(k==1||k>len)return head;
        ListNode*newHead=nullptr,*Tail1=head,*Tail2=nullptr;

        while(len>=k)
        {
            ListNode*curr=Tail1,*prev=nullptr,*next=nullptr;
            int counter=k;
            while(counter--)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if(newHead==nullptr)
            {
                newHead=prev;
            }
            if(Tail2)
            {
                Tail2->next=prev;
            }
            Tail1->next=curr;
            Tail2=Tail1;
            Tail1=curr;
            len-=k;
        }
        return newHead;
    }
};