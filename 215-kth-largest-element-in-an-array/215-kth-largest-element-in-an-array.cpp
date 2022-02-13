class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pque;
        for(int i=0;i<k;i++)
        {
            pque.push(nums[i]);
        }
        int n=nums.size();
        for(int i=k;i<n;i++)
        {
            if(pque.top()<nums[i])
            {
                            pque.pop();
            pque.push(nums[i]);
            }

        }
        return pque.top();
    }
};