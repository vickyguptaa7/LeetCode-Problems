class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int res=0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]+nums[i-1]>nums[i-2])
            {
                return nums[i-2]+nums[i-1]+nums[i];
            }
        }
        return res;
    }
};