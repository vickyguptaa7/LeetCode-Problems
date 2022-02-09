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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return root;
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==nullptr)
            {
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr)
            {
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode*parent=root,*child=root->right;
                while(child->left!=nullptr)
                {
                    parent=child;
                    child=child->left;
                }
                if(parent==root)
                {
                    root->right=child->right;
                }
                else
                {
                    parent->left=child->right;
                }
                root->val=child->val;
                delete child;
                return root;
            }
        }
        return root;
    }
};



























/*
        if(!root)return nullptr;
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==nullptr)
            {
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr)
            {
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode*parent=root,*curr=root->right;
                while(curr->left!=nullptr)
                {
                    parent=curr;
                    curr=curr->left;
                }
                if(parent==root)
                {
                    parent->right=curr->right;
                }
                else
                {
                    parent->left=curr->right;
                }
                root->val=curr->val;
                delete curr;
                return root;
            }
                
        }
        return root;
*/