/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* helper(int clvl,int& indx,int& lvl,string& traversal)
    {
        cout<<lvl<<" "<<indx<<"\n";
        if(clvl>lvl||indx==traversal.size())
        {
            return nullptr;
        }
        string num;
        while(indx<traversal.size()&&traversal[indx]>='0'&&traversal[indx]<='9')
        {
            num+=traversal[indx];
            indx++;
        }
        lvl=0;
        while(indx<traversal.size()&&traversal[indx]=='-')
        {
            indx++;
            lvl++;
        }
        TreeNode*root=new TreeNode(stoi(num));
        root->left=helper(clvl+1,indx,lvl,traversal);
        root->right=helper(clvl+1,indx,lvl,traversal);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int indx=0,lvl=0;
        return helper(0,indx,lvl,traversal);
    }
};