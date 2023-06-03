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

class mycomp {
    public:
       bool operator()(ListNode* a, ListNode* b){
           return a->val>b->val;
      }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,mycomp>pque;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]==nullptr)continue;
            pque.push(lists[i]);
        }
        ListNode*head=new ListNode(0);
        ListNode*ptr=head;
        while(!pque.empty())
        {
            ListNode*curr=pque.top();
            pque.pop();
            ptr->next=curr;
            ptr=ptr->next;
            if(curr->next)
            {
                pque.push(curr->next);
            }
            ptr->next=nullptr;
        }
        return head->next;
    }
};