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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*>mmp;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=dummy;
        int preSum=0;
        while(curr)
        {
            preSum+=curr->val;
            if(mmp.count(preSum))
            {
                curr=mmp[preSum]->next;
                int p=preSum+curr->val;
                while(p!=preSum)
                {
                    mmp.erase(p);
                    curr=curr->next;
                    p+=curr->val;
                }
                mmp[preSum]->next=curr->next;
            }
            else
                mmp[preSum]=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};