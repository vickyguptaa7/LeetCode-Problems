class listNode
{
    public:
    int val;
    listNode*next,*prev;
    listNode(int v)
    {
        val=v;
        next=nullptr;
        prev=nullptr;
    }
};

class MyCircularQueue {
    listNode*head,*tail;
    int size,currSize;
public:
    MyCircularQueue(int k) {
        size=k;
        currSize=0;
        head=nullptr;
    }
    
    bool enQueue(int value) {
        if(currSize==size)return false;
        
        listNode*newNode=new listNode(value);
        if(head==nullptr)
        {
            head=newNode;
            tail=newNode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            head->next=newNode;
            newNode->prev=head;
            newNode->next=tail;
            tail->prev=newNode;
            head=newNode;
            
        }
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(currSize==0)return false;
        
        if(currSize==1)
        {
            currSize=0;
            head=nullptr;
            tail=nullptr;
            return true;
        }
        
        tail=tail->next;
        head->next=tail;
        tail->prev=head;
        currSize--;
        return true;
    }
    
    int Front() {
        return (!tail)?-1:tail->val;
    }
    
    int Rear() {
        return (!head)?-1:head->val;
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize==size;
    }
    
    void display()
    {
        if(head==nullptr)return;
        listNode *temp=head;
        cout<<head->val<<" ";
        temp=temp->next;
        while(head!=temp)
        {
            cout<<head->val<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */