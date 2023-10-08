class Solution {
public:
    
    int helper(int i1,int i2,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(i1==nums1.size()||i2==nums2.size())
            return -1e9;
        
        if(dp[i1][i2]!=-1e9)
            return dp[i1][i2];
        
        return dp[i1][i2]=max({helper(i1+1,i2,nums1,nums2,dp),helper(i1,i2+1,nums1,nums2,dp),
                    max(helper(i1+1,i2+1,nums1,nums2,dp),0)+nums1[i1]*nums2[i2]});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1e9));
        return helper(0,0,nums1,nums2,dp);
    }
};