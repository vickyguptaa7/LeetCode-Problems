/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    int indx=0;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        string result= to_string(root->val)+" "
            +serialize(root->left)+" "+serialize(root->right);
        return result;
    }
    TreeNode*helper(string &data)
    {
        string word;
        while(indx<data.size()&&data[indx]!=' ')
        {
            word+=data[indx];
            indx++;
        }
        indx++;
        if(word.empty()||word=="#")
            return nullptr;
        TreeNode*root= new TreeNode(stoi(word));
        root->left=deserialize(data);
        root->right=deserialize(data);
        return root; 
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return helper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));