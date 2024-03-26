class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[nums[i]-1],nums[i]);
                i--;
            }
        }
        int res=1;
        for(auto &num:nums)
        {
            if(res==num)res++;
            else break;
        }
        return res;
    }
};