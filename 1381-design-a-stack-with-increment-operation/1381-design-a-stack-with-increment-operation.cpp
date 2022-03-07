class CustomStack {
public:
    int *arr,top,Size,*inc;
    CustomStack(int maxSize) {
        arr=new int[maxSize];
        inc=new int[maxSize];
        top=0;
        Size=maxSize;
    }
    
    void push(int x) {
        if(top==Size)
        {
            return;
        }
        arr[top]=x;
        inc[top]=0;
        top++;
    }
    
    int pop() {
        if(top==0)return -1;
        top--;
        int res=inc[top]+arr[top];
        if(top!=0)
        {
            inc[top-1]+=inc[top];
        }
            return res;

    }
    
    void increment(int k, int val) {
        int Max=min(k,top);
        if(Max-1>=0)
        {
            inc[Max-1]+=val;
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