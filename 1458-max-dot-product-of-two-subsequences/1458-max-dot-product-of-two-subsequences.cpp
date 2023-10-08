class Solution {
public:
    
    int helper(int i1,int i2,int k,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<int>>>&dp)
    {
        if(i1==nums1.size()||i2==nums2.size())
            return k==0?0:-1e9;
        
        if(dp[i1][i2][k]!=-1e9)
            return dp[i1][i2][k];
        
        return dp[i1][i2][k]=max({helper(i1+1,i2,k,nums1,nums2,dp),helper(i1,i2+1,k,nums1,nums2,dp),
                    helper(i1+1,i2+1,0,nums1,nums2,dp)+nums1[i1]*nums2[i2]});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1e9)));
        return helper(0,0,1,nums1,nums2,dp);
    }
};