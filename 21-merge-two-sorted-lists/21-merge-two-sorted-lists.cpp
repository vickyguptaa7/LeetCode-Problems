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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        ListNode*merge=nullptr,*iter=nullptr;
        while(list1&&list2)
        {
            if(list1->val>list2->val)
            {
                if(merge==nullptr)
                {
                    merge=list2;
                    iter=merge;
                    list2=list2->next;
                }
                else
                {
                    iter->next=list2;
                    iter=iter->next;
                    list2=list2->next;
                }
            }
            else
            {
                if(merge==nullptr)
                {
                    merge=list1;
                    iter=merge;
                    list1=list1->next;
                }
                else
                {
                    iter->next=list1;
                    iter=iter->next;
                    list1=list1->next;
                }
            }
        }
        if(list2)
        {
            iter->next=list2;
        }
        if(list1)
        {
            iter->next=list1;
        }
        return merge;
    }
};