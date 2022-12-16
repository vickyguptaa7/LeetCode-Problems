class MyQueue {
public:
    stack<int>t1,t2;
    MyQueue() {
        
    }
    
    void push(int x) {
        t1.push(x);
    }
    
    int pop() {
        while(t1.size()>1)
        {
            t2.push(t1.top());
            t1.pop();
        }
        int val=t1.top();
        t1.pop();
        while(!t2.empty())
        {
            t1.push(t2.top());
            t2.pop();
        }
        return val;
    }
    
    int peek() {
        while(t1.size()>1)
        {
            t2.push(t1.top());
            t1.pop();
        }
        int val=t1.top();
        while(!t2.empty())
        {
            t1.push(t2.top());
            t2.pop();
        }
        return val;
    }
    
    bool empty() {
        return t1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */