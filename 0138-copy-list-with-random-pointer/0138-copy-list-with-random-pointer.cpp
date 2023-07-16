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
        map<Node*,Node*>mpp;
        Node*curr=head->next,*nhead=new Node(head->val),*tail=nhead;
        mpp[head]=nhead;
        while(curr)
        {
            tail->next=new Node(curr->val);
            tail=tail->next;
            mpp[curr]=tail;
            curr=curr->next;
        }
        curr=head;
        Node *ncurr=nhead;
        while(curr)
        {
            ncurr->random=mpp[curr->random];
            curr=curr->next;
            ncurr=ncurr->next;
        }
        return nhead;
    }
};