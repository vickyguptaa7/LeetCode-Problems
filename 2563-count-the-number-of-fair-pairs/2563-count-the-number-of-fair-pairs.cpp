class Solution {
public:
    
    long long helper(vector<int>&nums,int upper)
    {
        int left=0,right=nums.size()-1;
        long long ans=0;
        while(left<right)
        {
            if(nums[left]+nums[right]<=upper)
            {
                ans+=right-left;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return helper(nums,upper)-helper(nums,lower-1);
    }
};