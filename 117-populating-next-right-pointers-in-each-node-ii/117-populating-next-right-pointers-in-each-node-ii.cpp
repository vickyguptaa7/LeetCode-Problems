/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        
        queue<Node*>que;
        que.push(root);
        root->next=nullptr;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                Node*curr=que.front();
                que.pop();
                if(curr->left)que.push(curr->left);
                if(curr->right)que.push(curr->right);
            }
            if(que.empty())break;

            Node*curr=que.front();
            Node*rep=curr;
            que.pop();
            while(!que.empty()&&que.front()!=rep)
            {
                curr->next=que.front();
                que.push(curr);
                curr=que.front();
                que.pop();
            }
            curr->next=nullptr;
            que.push(curr);
        }
        return root;
    }
};