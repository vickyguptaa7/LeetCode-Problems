class Solution {
public:
    bool check(vector<int>& nums) {
        int size=nums.size();
        int inv=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
                inv++;
        }
        if(nums[size-1]>nums[0])
            inv++;
            
        return inv<=1;
    }
};