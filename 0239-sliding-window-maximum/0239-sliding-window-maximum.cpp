class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dque;
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            while(!dque.empty()&&nums[dque.back()]<=nums[i])
            {
                dque.pop_back();
            }
            while(!dque.empty()&&dque.front()<i-(k-1))
                dque.pop_front();
            dque.push_back(i);
            if(i>=k-1)
            {
                result.push_back(nums[dque.front()]);
            }
        }
        return result;
    }
};