class Solution {
public:
    
    int helper(int it1,int it2,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(it1==nums1.size()||it2==nums2.size())
            return 0;
        
        if(dp[it1][it2]!=-1)
            return dp[it1][it2];
        
        int ways=helper(it1+1,it2,nums1,nums2,dp);
        
        for(int i=it2;i<nums2.size();i++)
        {
            if(nums1[it1]==nums2[i])
            {
                ways=max(ways,1+helper(it1+1,i+1,nums1,nums2,dp));
            }
        }
        
        return dp[it1][it2]=ways;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(0,0,nums1,nums2,dp);
    }
};