class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pque;
        for(auto &num:nums)
        {
            pque.push(num);
            if(pque.size()>k)
                pque.pop();
        }
        return pque.top();
    }
};