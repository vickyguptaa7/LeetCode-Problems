class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=0,freq=1,n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[major]==nums[i])freq++;
            else
            {
                freq--;
                if(freq==0)
                {
                    major=i;
                    freq=1;
                }
            }
        }
        return nums[major];
    }
};