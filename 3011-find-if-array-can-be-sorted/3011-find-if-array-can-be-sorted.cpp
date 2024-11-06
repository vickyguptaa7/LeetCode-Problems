class Solution {
public:
    
    bool canSortArray(vector<int>& nums) {
        int mn=nums[0],mx=nums[0];
        int pmn=0,pmx=0;
        for(int i=1;i<nums.size();i++)
        {
            if(__builtin_popcount(nums[i-1])!=__builtin_popcount(nums[i]))
            {
                if(pmx>mn)
                {
                    return false;
                }
                pmn=mn;
                pmx=mx;
                mn=nums[i];
                mx=nums[i];
            }
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        return pmx>mn?false:true;
    }
};