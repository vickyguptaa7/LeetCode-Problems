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
    int findLen(ListNode*head)
    {
        int len=0;
        while(head!=nullptr)
        {
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode* findKthNode(ListNode*head,int k)
    {
        int it=k-1;
        while(it)
        {
            head=head->next;
            --it;
        }
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*node1=findKthNode(head,k);
        ListNode*node2=findKthNode(head,findLen(head)-k+1);
        int temp=node1->val;
        node1->val=node2->val;
        node2->val=temp;
        return head;
    }
};