class Solution {
public:
    
    int helper(int it1,int it2,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(it1==nums1.size()||it2==nums2.size())
            return 0;
        
        if(dp[it1][it2]!=-1)
            return dp[it1][it2];
        
        if(nums1[it1]==nums2[it2])
            return dp[it1][it2]=1+helper(it1+1,it2+1,nums1,nums2,dp);
        else 
            return dp[it1][it2]=max(helper(it1+1,it2,nums1,nums2,dp),
                                    helper(it1,it2+1,nums1,nums2,dp));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(0,0,nums1,nums2,dp);
    }
};