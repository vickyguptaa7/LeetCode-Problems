class Solution {
    int dp[501][501][2];
public:

    int helper(int x,int y,int taken,vector<int>&nums1,vector<int>&nums2)
    {
        int n=nums1.size(),m=nums2.size();
        if(x>=n||y>=m)
            return taken>0?0:-1e9;
        
        if(dp[x][y][taken]!=-1)
            return dp[x][y][taken];
        
        return dp[x][y][taken]=max({helper(x+1,y,taken,nums1,nums2),helper(x,y+1,taken,nums1,nums2),helper(x+1,y+1,1,nums1,nums2)+nums1[x]*nums2[y]});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,nums1,nums2);
    }
};