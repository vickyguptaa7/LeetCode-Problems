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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*it1=list1;
        int iter=0;
        while(++iter<a)
        {
            it1=it1->next;
        }
        b-=a-1;
        ListNode*it2=it1->next;
        it1->next=list2;
        iter=0;
        while(iter++<b)
        {
            it2=it2->next;
        }
        while(it1->next)
        {
            it1=it1->next;
        }
        it1->next=it2;
        return list1;
    }
};