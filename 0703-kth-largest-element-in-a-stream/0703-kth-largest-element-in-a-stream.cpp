class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>>pque;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto x:nums)add(x);
    }
    
    int add(int val) {
        pque.push(val);
        if(pque.size()>k)
            pque.pop();
        return pque.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */