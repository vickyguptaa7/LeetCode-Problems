class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,prev=0,size=1e9;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                size=min(size,i-prev+1);
                sum-=nums[prev];
                prev++;
            }
        }
        return size==1e9?0:size;
    }
};