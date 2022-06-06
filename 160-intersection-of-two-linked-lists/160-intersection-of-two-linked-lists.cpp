/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int ListLength(ListNode*head)
    {
        int length=0;
        while(head)
        {
            head=head->next;
            length++;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=ListLength(headA);
        int lenB=ListLength(headB);
        if(lenA<lenB)
        {
            return getIntersectionNode(headB,headA);
        }
        int diff=lenA-lenB;
        while(diff)
        {
            headA=headA->next;
            diff--;
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};