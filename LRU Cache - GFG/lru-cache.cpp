//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node
{
    public:
    int val;
    Node*next;
    Node*prev;
    Node(int val)
    {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};
class DLinkedList
{
    Node*head,*tail;
    int len;
    int cap;
    public:
    DLinkedList()
    {
        head=nullptr;
        tail=nullptr;
        len=0;
    }
    Node* addNodeToHead(int val)
    {
        Node* node=new Node(val);
        if(!head)
        {
            head=node;
            tail=node;
        }
        else
        {
            head->prev=node;
            node->next=head;
            head=node;
        }
        len++;
        return node;
    }
    
    Node* removeLastNode()
    {
        Node*address=tail;
        removeNode(tail);
        return address;
    }
    
    void removeNode(Node*node)
    {
        if(!node->next&&!node->prev)
        {
            tail=nullptr;
            head=nullptr;
        }
        else if(!node->next)
        {
            Node*del=node;
            node=node->prev;
            node->next=nullptr;
            tail=node;
            delete del;
        }
        else if(!node->prev)
        {
            Node*del=node;
            node=node->next;
            node->prev=nullptr;
            head=node;
            delete del;
        }
        else
        {
            Node*del=node;
            node->prev->next=node->next;
            node->next->prev=node->prev;
            delete del;
        }
        len--;
    }
    
    Node* placeToFirst(Node*node,int val)
    {
        removeNode(node);
        return addNodeToHead(val);
    }
    
    // void traverse()
    // {
    //     Node*curr=head;
    //     while(curr)
    //     {
    //         cout<<curr->val<<"->";
    //         curr=curr->next;
    //     }
    //     cout<<"\n";
    // }
    
    int size()
    {
        return len;
    }
};
class LRUCache
{
    private:
    unordered_map<int,Node*>mpp;
    unordered_map<Node*,int>keympp;
    DLinkedList *l1;
    int cap;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        l1=new DLinkedList();
        this->cap=cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(!mpp.count(key))
            return -1;
        mpp[key]=l1->placeToFirst(mpp[key],mpp[key]->val);
        keympp[mpp[key]]=key;
        return mpp[key]->val;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(!mpp.count(key))
        {
            if(l1->size()==cap)
            {
                Node*address=l1->removeLastNode();
                
                int remkey=keympp[address];
                keympp.erase(address);
                mpp.erase(remkey);
                
                Node*node=l1->addNodeToHead(value);
                mpp[key]=node;
                keympp[node]=key;
            }
            else
            {
                Node*node=l1->addNodeToHead(value);
                mpp[key]=node; 
                keympp[node]=key;
            }
        }
        else
        {
            mpp[key]=l1->placeToFirst(mpp[key],value); 
            keympp[mpp[key]]=key;
        }
        // l1->traverse();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends