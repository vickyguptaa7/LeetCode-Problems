class CustomStack {
public:
    int *arr,top,Size;
    CustomStack(int maxSize) {
        arr=new int[maxSize];
        top=0;
        Size=maxSize;
    }
    
    void push(int x) {
        if(top==Size)
        {
            return;
        }
        arr[top]=x;
        top++;
    }
    
    int pop() {
        if(top==0)return -1;
        top--;
        return arr[top];
    }
    
    void increment(int k, int val) {
        int Max=min(k,top);
        for(int i=0;i<Max;i++)
        {
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */