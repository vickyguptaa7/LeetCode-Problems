class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int repeated=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            else 
            {
                repeated=abs(nums[i]);
                break;
            }
        }
        for(auto &x:nums)x=abs(x);
        return repeated;
    }
};