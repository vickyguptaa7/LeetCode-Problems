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
    string preorder(TreeNode*root)
    {
        if(!root)return "";
        string left=serialize(root->left);
        string right=serialize(root->right);
        return to_string(root->val)+" "+left+right;
    }
    string serialize(TreeNode* root) {
        string s=preorder(root);
        // cout<<s<<"\n";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* preorderToTree(vector<int> &arr,int &s,int min,int max)
    {
        if(s>=arr.size()||(arr[s]<min||arr[s]>max))return nullptr;
        int temp=s;
        TreeNode* newNode=new TreeNode(arr[s++]);
        newNode->left=preorderToTree(arr,s,min,arr[temp]);
        newNode->right=preorderToTree(arr,s,arr[temp],max);
        return newNode;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        vector<int>arr;
        while (getline (ss, item, ' '))
        {
            arr.push_back(stoi(item));
        }
        int s=0;
        return preorderToTree(arr,s,-1,1e4+1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;