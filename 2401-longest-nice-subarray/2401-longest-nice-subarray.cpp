class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long head=-1,tail=0;
        long long curr_sum=0,curr_xor=0,max_window=0;
        nums.push_back(0);
        while(tail<nums.size())
        {
            while(head+1<nums.size()&&curr_sum==curr_xor)
            {
                head++;
                curr_sum+=nums[head];
                curr_xor^=nums[head];
            }
            max_window=max(max_window,head-tail);
            if(tail>head)
            {
                head=tail;
            }
            else
            {
                curr_sum-=nums[tail];
                curr_xor^=nums[tail];
                tail++;
            }
        }
        return max_window;
    }
};