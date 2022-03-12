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
        if(head==nullptr)return nullptr;
        Node*curr=head;
        while(curr)
        {
            Node*newnode=new Node(curr->val);
            newnode->next=curr->next;
            curr->next=newnode;
            curr=curr->next->next;
        }
        curr=head;
        while(curr)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            else
                curr->next->random=nullptr;
            
            curr=curr->next->next;
        }
        Node*newHead=head->next;
        curr=newHead;
        while(curr&&curr->next)
        {
            head->next=curr->next;
            curr->next=curr->next->next;
            curr=curr->next;
            head=head->next;
        }
        head->next=nullptr;
        return newHead;
    }
};

/*
class Solution { // O(n) Space Used In Map
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>umap;
        Node*curr=head;
        while(curr)
        {
            Node*newnode=new Node(curr->val);
            umap[curr]=newnode;
            curr=curr->next;
        }
        curr=head;
        while(curr)
        {
            umap[curr]->next=umap[curr->next];
            umap[curr]->random=umap[curr->random];
            curr=curr->next;
        }
        return umap[head];
    }
};
*/