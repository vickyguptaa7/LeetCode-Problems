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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preorder(root,res);
        res=res.substr(1);
        cout<<res<<"\n";
        return res;
    }
    void preorder(TreeNode*root,string &res)
    {
        if(!root)
        {
            res+=",-1001";
            return;
        }
        res+=",";
        res+=to_string(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }// Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        int iter=0;
        return helper(data,iter);
    }
    TreeNode*helper(string &data,int&iter)
    {
        int val=Decode(data,iter);
        if(val==-1001)
        {
            return nullptr;
        }
        TreeNode*root=new TreeNode(val);
        root->left=helper(data,iter);
        root->right=helper(data,iter);
        return root;
    }
    int Decode(string &s,int& iter)
    {
        string res;
        for(int i=iter;i<s.length();i++)
        {
            if(s[i]!=',')
            res+=s[i];
            else break;
        }
        if(s.length()!=res.length()){
            iter+=res.length()+1;
        }
        else {
            iter+=res.length();
        }
        if(res.length()==0)return -1001;
        return stoi(res);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));