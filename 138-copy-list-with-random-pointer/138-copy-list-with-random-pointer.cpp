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