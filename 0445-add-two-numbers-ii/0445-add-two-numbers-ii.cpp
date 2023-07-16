/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    ListNode* reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            l1 = reverseList(l1);
            l2 = reverseList(l2);
            ListNode*head=nullptr,*tail=nullptr;
            int carry = 0;
            while (l1 || l2 || carry)
            {
                int sum = 0;
                if (l1)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }
                sum += carry;
                carry = sum / 10;
                sum %= 10;
                if (!head)
                {
                    head = new ListNode(sum);
                    tail = head;
                }
                else
                {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }
            }
            return reverseList(head);
        }
};