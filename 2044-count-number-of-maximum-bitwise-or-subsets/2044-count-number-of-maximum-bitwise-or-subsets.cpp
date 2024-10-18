class Solution {
public:
    
    int helper(int indx,int orr,int ans,vector<int>&nums)
    {
        if(indx==nums.size())
        {
            return orr==ans;
        }
        return helper(indx+1,orr,ans,nums)+helper(indx+1,orr|(nums[indx]),ans,nums);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)ans|=nums[i];
        return helper(0,0,ans,nums);
    }
};