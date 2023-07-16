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
    
    void addNodeToTail(ListNode*&head,ListNode*&tail,ListNode*&node)
    {
        if(!head)
        {
            head=node;
            tail=node;
            node=node->next;
            tail->next=nullptr;
            return;
        }
        tail->next=node;
        tail=tail->next;
        node=node->next;
        tail->next=nullptr;
        
    }
    
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*lessHead=nullptr,*moreHead=nullptr;
        ListNode*lessTail=nullptr,*moreTail=nullptr;
        ListNode*curr=head;
        while(curr)
        {
            if(curr->val>=x)
            {
                addNodeToTail(moreHead,moreTail,curr);
            }
            else
            {
                addNodeToTail(lessHead,lessTail,curr);
            }
        }
        if(!lessHead)
            return moreHead;
        if(!moreHead)
            return lessHead;
        lessTail->next=moreHead;
        return lessHead;
    }
};