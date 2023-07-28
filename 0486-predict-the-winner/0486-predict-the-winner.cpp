class Solution {
public:
    
    int helper(int sIndx,int eIndx,bool isPlayerOne,vector<int>&nums,
               vector<vector<vector<int>>>&dp)
    {
        if(sIndx>eIndx)
            return 0;
        
        if(dp[sIndx][eIndx][isPlayerOne]!=-1)
            return dp[sIndx][eIndx][isPlayerOne];
        
        if(isPlayerOne)
        {
            return dp[sIndx][eIndx][isPlayerOne]=
                max(nums[sIndx]+helper(sIndx+1,eIndx,!isPlayerOne,nums,dp),
                      nums[eIndx]+helper(sIndx,eIndx-1,!isPlayerOne,nums,dp));
        }
        else
        {
            return dp[sIndx][eIndx][isPlayerOne]=
                min(helper(sIndx+1,eIndx,!isPlayerOne,nums,dp),
                      helper(sIndx,eIndx-1,!isPlayerOne,nums,dp));
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        int playerOneScore=helper(0,n-1,1,nums,dp);
        
        int totalScore=accumulate(nums.begin(),nums.end(),0);
        
        return totalScore<=playerOneScore*2;
    }
};