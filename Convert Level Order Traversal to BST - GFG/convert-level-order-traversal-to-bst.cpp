// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.

Node* constructBst(int arr[], int n)
{
    queue<pair<Node*,pair<int,int>>>que;
    int indx=0;
    Node*root=new Node(arr[indx++]);
    que.push({root,{INT_MIN,INT_MAX}});
    while(indx<n&&!que.empty())
    {
        auto curr=que.front();
        que.pop();
        
        if(
            indx<n && 
            arr[indx]<curr.first->data && 
            arr[indx]>curr.second.first
        )
        {
            Node*newNode=new Node(arr[indx++]);
            curr.first->left=newNode;
            que.push({newNode,{curr.second.first,curr.first->data}});
        }
        
        if(
            indx<n &&
            arr[indx]>curr.first->data &&
            arr[indx]<curr.second.second
        )
        {
            Node*newNode=new Node(arr[indx++]);
            curr.first->right=newNode;
            que.push({newNode,{curr.first->data,curr.second.second}});
        }
    }
    
    return root;
}
