class Solution {
public:
    
    int helper(int sIndx,int eIndx,bool isPlayerOne,vector<int>&nums,
               vector<vector<int>>&dp)
    {
        if(sIndx>eIndx)
            return 0;
        
        if(dp[sIndx][eIndx]!=-1)
            return dp[sIndx][eIndx];
        
        if(isPlayerOne)
        {
            return dp[sIndx][eIndx]=
                max(nums[sIndx]+helper(sIndx+1,eIndx,!isPlayerOne,nums,dp),
                      nums[eIndx]+helper(sIndx,eIndx-1,!isPlayerOne,nums,dp));
        }
        else
        {
            return dp[sIndx][eIndx]=
                min(helper(sIndx+1,eIndx,!isPlayerOne,nums,dp),
                      helper(sIndx,eIndx-1,!isPlayerOne,nums,dp));
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int playerOneScore=helper(0,n-1,1,nums,dp);
        
        int totalScore=accumulate(nums.begin(),nums.end(),0);
        
        return totalScore<=playerOneScore*2;
    }
};