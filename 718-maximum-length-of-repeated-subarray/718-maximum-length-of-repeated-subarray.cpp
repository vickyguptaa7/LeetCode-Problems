class Solution {
public:
    
    int helper(int s1,int s2,int n1,int n2,int &maxLen,vector<int>&nums1,vector<int>&nums2,
              vector<vector<int>>&dp)
    {
        if(s1==n1||s2==n2)return 0;
        
        if(dp[s1][s2]!=-1)return dp[s1][s2];
        
        if(nums1[s1]==nums2[s2])
        {
            dp[s1][s2]=helper(s1+1,s2+1,n1,n2,maxLen,nums1,nums2,dp)+1;
            maxLen=max(maxLen,dp[s1][s2]);
        }
        maxLen=max(maxLen,helper(s1,s2+1,n1,n2,maxLen,nums1,nums2,dp));
        maxLen=max(maxLen,helper(s1+1,s2,n1,n2,maxLen,nums1,nums2,dp));
        return dp[s1][s2]=max(0,dp[s1][s2]);
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int maxLen=0;
        helper(0,0,n1,n2,maxLen,nums1,nums2,dp);
        return maxLen;
    }
};