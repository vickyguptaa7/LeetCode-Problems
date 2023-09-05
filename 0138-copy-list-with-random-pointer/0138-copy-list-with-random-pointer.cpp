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
            Node*next=curr->next;
            Node*nnode=new Node(curr->val);
            curr->next=nnode;
            nnode->next=next;
            curr=next;
        }
        curr=head;
        while(curr&&curr->next)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            else
                curr->next->random=nullptr;
            curr=curr->next->next;
        }
        Node*nhead=head->next;
        head->next=head->next->next;
        curr=head->next;
        Node*tail=nhead;
        while(curr)
        {
            tail->next=curr->next;
            tail=tail->next;
            curr->next=curr->next->next;
            curr=curr->next;
        }
        return nhead;
    }
};