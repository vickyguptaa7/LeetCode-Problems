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
    
    ListNode*findMiddle(ListNode*head)
    {
        ListNode*slow=head,*fast=head->next;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode*head1,ListNode*head2)
    {
        ListNode*head=nullptr,*tail=nullptr;
        while(head1&&head2)
        {
            if(head1->val>head2->val)
            {
                addNodeToTail(head,tail,head2);
            }
            else
            {
                addNodeToTail(head,tail,head1);
            }
        }
        while(head1)
        {
            addNodeToTail(head,tail,head1);
        }
        while(head2)
        {
            addNodeToTail(head,tail,head2);
        }
        return head;
    }
    ListNode* mergeSort(ListNode*head)
    {
        if(!head||!head->next)
            return head;
        ListNode*middle=findMiddle(head);
        ListNode*left=head,*right=middle->next;
        middle->next=nullptr;
        ListNode*nleft=mergeSort(left);
        ListNode*nright=mergeSort(right);
        return merge(nleft,nright);
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode*newhead=mergeSort(head);
        return newhead;
    }
};