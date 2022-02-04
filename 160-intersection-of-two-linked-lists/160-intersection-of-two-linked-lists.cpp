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
    int length_ll(ListNode*head)
    {
        ListNode*temp=head;
        int length=0;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lengthA=length_ll(headA);
        int lengthB=length_ll(headB);
        if(lengthA<lengthB)
        {
            return getIntersectionNode(headB,headA);
        }
        int difference=lengthA-lengthB;
        
        ListNode*currA=headA,*currB=headB;
        
        while(difference--)
        {
            currA=currA->next;
        }
        
        while(currA!=currB)
        {
            currA=currA->next;
            currB=currB->next;
        }
        return currA;
    }
};