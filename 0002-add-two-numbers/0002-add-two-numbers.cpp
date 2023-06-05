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
    ListNode*reverseList(ListNode*head)
    {
        ListNode*curr=head,*prev=nullptr,*next=nullptr;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*rl1=l1,*rl2=l2;

        int carry=(rl1->val+rl2->val)/10;
        
        ListNode*head=new ListNode((rl1->val+rl2->val)%10);
        ListNode*iter=head;
        
        rl1=rl1->next;
        rl2=rl2->next;
        
        while(rl1||rl2)
        {
            int sum=0;
            if(rl1)
            {
                sum+=rl1->val;
                rl1=rl1->next;
            }
            if(rl2)
            {
                sum+=rl2->val;
                rl2=rl2->next;
            }
            sum+=carry;
            carry=sum/10;
            iter->next=new ListNode(sum%10);
            iter=iter->next;
        }
        if(carry)
            iter->next=new ListNode(carry);
        
        return head;
    }
};