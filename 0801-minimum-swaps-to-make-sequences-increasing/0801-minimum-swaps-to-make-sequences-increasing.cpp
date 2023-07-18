class Solution {
public:
    
    int helper(int indx,bool isSwap,vector<int>&nums1,vector<int>&nums2,
               vector<vector<int>>&dp)
    {
        if(indx==nums1.size())
        {
            return 0;
        }
        if(dp[indx][isSwap]!=-1)
            return dp[indx][isSwap];
        int minSwap=1e9;
        if(isSwap)
        {
            if(nums1[indx]>nums2[indx-1]&&nums2[indx]>nums1[indx-1])
            {
                minSwap=helper(indx+1,0,nums1,nums2,dp);
            }
            if(nums1[indx]>nums1[indx-1]&&nums2[indx]>nums2[indx-1])
            {
                minSwap=min(minSwap,1+helper(indx+1,1,nums1,nums2,dp));
            }
            return dp[indx][isSwap]=minSwap;
        }
        else
        {
            if(nums1[indx]>nums1[indx-1]&&nums2[indx]>nums2[indx-1])
            {
                minSwap=min(minSwap,helper(indx+1,0,nums1,nums2,dp));
            }
            if(nums1[indx]>nums2[indx-1]&&nums2[indx]>nums1[indx-1])
            {
                minSwap=min(minSwap,1+helper(indx+1,1,nums1,nums2,dp));
            }
            return dp[indx][isSwap]=minSwap;
        }
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return min(helper(1,0,nums1,nums2,dp),1+helper(1,1,nums1,nums2,dp));
    }
};