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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mnDist=1e9,mxDist=-1;
        ListNode*curr=head->next,*prev=head,*next=nullptr;
        vector<int>arr;
        int len=0;
        while(curr&&curr->next)
        {
            len++;
            next=curr->next;
            if(prev->val>curr->val&&next->val>curr->val)
            {
                arr.push_back(len);
            }
            else if(prev->val<curr->val&&next->val<curr->val)
            {
                arr.push_back(len);
            }
            prev=curr;
            curr=curr->next;
        }
        if(arr.size()<2)
            return {-1,-1};
        for(int i=1;i<arr.size();i++)mnDist=min(mnDist,arr[i]-arr[i-1]);
        return {mnDist,arr.back()-arr.front()};
    }
};