class Solution {
public:
    
    int helper(int it1,int it2,bool isPrevSame,vector<int>&nums1,
               vector<int>&nums2,vector<vector<vector<int>>>&dp,int &len)
    {
        if(it1==nums1.size()||it2==nums2.size())
            return 0;
        
        if(dp[it1][it2][isPrevSame]!=-1)
            return dp[it1][it2][isPrevSame];
        
        int maxLen=0;
        if(nums1[it1]==nums2[it2])
        {
            maxLen=helper(it1+1,it2+1,true,nums1,nums2,dp,len)+1;
        }
        maxLen=max(maxLen,helper(it1+1,it2,false,nums1,nums2,dp,len));
        maxLen=max(maxLen,helper(it1,it2+1,false,nums1,nums2,dp,len));
        len=max(maxLen,len);
        return dp[it1][it2][isPrevSame]=isPrevSame?maxLen:0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,
        //                                     vector<int>(2,-1)));
        int len=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j]=0;
                }
                len=max(len,dp[i][j]);
            }
        }
        // helper(0,0,false,nums1,nums2,dp,len);
        return len;
    }
};