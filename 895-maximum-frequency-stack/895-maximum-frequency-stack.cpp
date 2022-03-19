class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>stck;
    int maxFreq=0;
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq=max(maxFreq,freq[val]);
        stck[freq[val]].push(val);
    }
    
    int pop() {
        int element=stck[maxFreq].top();
        stck[maxFreq].pop();
        freq[element]--;
        if(stck[maxFreq].empty())maxFreq--;
        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

