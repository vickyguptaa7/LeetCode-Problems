/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*>st;
        st.push(root);
        vector<int>post;
        Node*curr=nullptr;
        while(!st.empty())
        {
            curr=st.top();
            st.pop();
            if(!curr)continue;
            post.push_back(curr->val);
            for(int i=0;i<curr->children.size();i++)
            {
                st.push(curr->children[i]);
            }
        }
        reverse(post.begin(),post.end());
        return post;
    }
};