/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node*curr=head;
        while(curr)
        {
            Node*newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=curr->next->next;
        }
        
        curr=head;
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;
            }
            else
            {
                curr->next->random=nullptr;
            }
            curr=curr->next->next;
        }
        curr=head->next;
        Node*nhead=head->next;
        while(curr&&curr->next)
        {
            head->next=curr->next;
            head=head->next;
            curr->next=curr->next->next;
            curr=curr->next;
        }
        head->next=nullptr;
        return nhead;
    }
};