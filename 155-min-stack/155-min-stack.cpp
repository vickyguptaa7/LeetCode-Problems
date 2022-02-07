class MinStack {
public:
    stack<long long>st;
    long long Min;
    MinStack() {
        Min=1e12;
    }
    
    void push(int val) {
        if(Min>=val)
        {
            st.push(2ll*val-Min);
            Min=val;
        }
        else  
        {
            st.push(val);
        }
    }
    
    void pop() {
        if(Min>=st.top())
        {
            Min=2*Min-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.size()!=1&&st.top()>Min)
            return st.top();
        else 
            return Min;
    }
    
    int getMin() {
        return Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */