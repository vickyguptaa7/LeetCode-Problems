class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pque;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<k;i++)
        {
            if(nums.empty()||i>=nums.size())
            {
                pque.push(INT_MIN);
            }
            else
            pque.push(nums[i]);
            // cout<<pque.top()<<"\n";
        }
        for(int i=k;i<nums.size();i++)
        {
            if(pque.top()<=nums[i])
            {
                pque.pop();
                pque.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pque.top()<=val)
        {
            pque.pop();
            pque.push(val);
        }
        // cout<<pque.top()<<"\n";
        return pque.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */