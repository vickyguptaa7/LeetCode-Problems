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
    ListNode* reverse_List(ListNode*l1)
    {
        ListNode*curr=l1,*prev=nullptr,*next=nullptr;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverse_List(l1);
        // l2=reverse_List(l2);
        int carry=0;
        ListNode*h1=l1,*h2=l2;
        ListNode*result=nullptr,*h3=nullptr;
        while(h1!=nullptr||h2!=nullptr||carry!=0)
        {
            int sum=carry;
            if(h1!=nullptr)
            {
                sum+=h1->val;
                h1=h1->next;
            }
            if(h2!=nullptr)
            {
                sum+=h2->val;
                h2=h2->next;
            }
            carry=sum/10;
            ListNode*newNode=new ListNode(sum%10);
            if(h3==nullptr)
            {
                result=newNode;
                h3=newNode;
                h3->next=nullptr;
            }
            else
            {
                h3->next=newNode;
                h3=h3->next;
                h3->next=nullptr;
            }
        }
        return result;
    }
};