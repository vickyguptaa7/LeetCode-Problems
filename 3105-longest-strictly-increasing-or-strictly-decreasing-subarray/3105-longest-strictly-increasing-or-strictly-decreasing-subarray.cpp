class Solution {
public:
    
    int helper(vector<int>&nums)
    {
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[j-1])
                {
                    res=max(res,j-i+1);
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
    
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=helper(nums);
        reverse(nums.begin(),nums.end());
        res=max(res,helper(nums));
        return res;
    }
};