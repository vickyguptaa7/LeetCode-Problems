/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution
{
    void addChild(Node*&head,Node*&tail)
    {
        if (head->child)
            {
                Node *child = flatten(head->child);
                head = head->next;
                tail->next = child;
                child->prev = tail;
                while (child->next)
                {
                    child = child->next;
                }
                tail = child;
                tail->next=nullptr;
            }
            else 
                head = head->next;
    }
    public:
        Node* flatten(Node *head)
        {
            if (!head)
                return head;
            Node *nhead = head, *tail = head;
            addChild(head,tail);
            cout << nhead->val << " ";
            while (head)
            {
                cout << head->val << " ";
                tail->next = head;
                head->prev = tail;
                tail = tail->next;
                addChild(head,tail);
                tail->next = nullptr;
            }
            head = nhead;
            while (head)
            {
                head->child = nullptr;
                head = head->next;
            }
            cout<<"\n";
            return nhead;
        }
};