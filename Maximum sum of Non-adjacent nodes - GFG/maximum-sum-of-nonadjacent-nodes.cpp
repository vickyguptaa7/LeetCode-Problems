// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        map<Node*,int>dp;
        return Maximum_Sum_Of_Non_Adjacent_Nodes(root,dp);
    }
int Maximum_Sum_Of_Non_Adjacent_Nodes(Node *root, map<Node*, int> &dp)
{
    if (!root)
        return 0;

    if (dp[root])
        return dp[root];

    int withNode = root->data;
    if (root->left)
    {
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->left->right, dp);
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->left->left, dp);
    }
    if (root->right)
    {
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->right->right, dp);
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->right->left, dp);
    } 

    int withoutNode = 0;
    withoutNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->left, dp);
    withoutNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->right, dp);
    return dp[root]=max(withNode, withoutNode);
}

};

// { Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}  // } Driver Code Ends