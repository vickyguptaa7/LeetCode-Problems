class MyStack {
public:
    queue<int>que;
    MyStack() {
        
    }
    void push(int x) {
        reverseQue();
        que.push(x);
        reverseQue();
    }
    void reverseQue()
    {
        if(que.empty())
        {
            return;
        }
        int num=que.front();
        que.pop();
        reverseQue();
        que.push(num);
    }
    int pop() {
        int num=que.front();
        que.pop();
        return num;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */