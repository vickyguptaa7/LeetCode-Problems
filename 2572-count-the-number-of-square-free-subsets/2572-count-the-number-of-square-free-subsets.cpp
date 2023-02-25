class Solution {
public:
    vector<int>primes={2,3,5,7,11,13,17,19,23,29};
    int isPossible(int factor,int num)
    {
        int val=0;
        for(int i=0;i<10;i++)
        {
            if(num%(primes[i]*primes[i])==0)
            {
                return -1;
            }
            if(num%(primes[i])==0&&(factor&(1<<(i+1))))
            {
                return -1;
            }
            if(num%primes[i]==0)
                val|=(1<<(i+1));
        }
        return val;
    }
    
    int helper(int strt,int factor,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(strt==nums.size())
        {
            return 1;
        }
        if(dp[strt][factor]!=-1)
        {
            return dp[strt][factor];
        }
        long long ans=helper(strt+1,factor,nums,dp),mod=1e9+7;
        
        int val=isPossible(factor,nums[strt]);
        
        if((factor&val)==0)
        {
            ans+=helper(strt+1,(factor|val),nums,dp);
        } 
        return dp[strt][factor]=ans%mod;
            
    }
    int squareFreeSubsets(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>((1<<11),-1));
        int mod=1e9+7;
        return (helper(0,1,nums,dp)-1+mod)%mod;
    }
};