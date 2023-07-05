class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>dup;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]>0)
            {
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
            else
            {
                dup.push_back(abs(nums[i]));
            }
        }
        for(auto &x:nums)x=abs(x);
        return dup;
    }
};