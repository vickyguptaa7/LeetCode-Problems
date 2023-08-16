class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>maxInWindow;
        deque<int>dque;
        for(int i=0;i<nums.size();i++)
        {
            while(!dque.empty()&&nums[dque.back()]<nums[i])
            {
                dque.pop_back();
            }
            
            while(!dque.empty()&&dque.front()<i-k+1)
                dque.pop_front();
            
            dque.push_back(i);
            
            if(i+1>=k)
                maxInWindow.push_back(nums[dque.front()]);
        }
        return maxInWindow;
    }
};