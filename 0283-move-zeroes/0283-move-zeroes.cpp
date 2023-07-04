class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prev=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                prev++;
                swap(nums[prev],nums[i]);
            }
        }
    }
};