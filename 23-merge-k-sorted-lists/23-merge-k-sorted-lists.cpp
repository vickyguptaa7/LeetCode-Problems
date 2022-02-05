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

typedef pair<int,ListNode*> pp;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return nullptr;
        else if(n==1)return lists[0];
        
        ListNode*merge=nullptr,*nlist=nullptr;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr)
            pq.push({lists[i]->val,lists[i]});
        }
        if(pq.empty())return nullptr;
        nlist=pq.top().second;
        merge=nlist;
        pq.pop();
        if(merge->next)
        {
            pq.push({merge->next->val,merge->next});
        }
        while(!pq.empty())
        {
            ListNode* curr=pq.top().second;
            pq.pop();
            merge->next=curr;
            merge=merge->next;
            if(curr->next)
            {
               pq.push({curr->next->val,curr->next});
            }
        }
        merge->next=nullptr;
        return nlist;
    }
};