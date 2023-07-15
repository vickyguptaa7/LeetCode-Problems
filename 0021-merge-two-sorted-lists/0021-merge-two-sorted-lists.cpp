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
    
    void addNodeToList(ListNode*&head,ListNode*&tail,ListNode*&curr)
    {
        if(!head)
        {
            head=curr;
            tail=curr;
            curr=curr->next;
            return;
        }
        tail->next=curr;
        curr=curr->next;
        tail=tail->next;
        tail->next=nullptr;
    }
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*head=nullptr,*tail=nullptr;
        while(list1&&list2)
        {
            if(list1->val>list2->val)
            {
                addNodeToList(head,tail,list2);
            }
            else
            {
                addNodeToList(head,tail,list1);
            }
        }
        while(list1)
        {
            addNodeToList(head,tail,list1);
        }
        while(list2)
        {
            addNodeToList(head,tail,list2);
        }
        return head;
    }
};