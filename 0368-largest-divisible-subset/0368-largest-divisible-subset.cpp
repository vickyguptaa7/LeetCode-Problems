class Solution {
public:
    
    // memo
    int helper(int curr,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(curr==nums.size())
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        int consider=0;
        if(prev==-1||nums[curr]%nums[prev]==0)
        {
            consider=helper(curr+1,curr,nums,dp)+1;
        }
        int dontConsider=helper(curr+1,prev,nums,dp);
        return dp[curr][prev+1]=max(consider,dontConsider);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,0);
        
        //tabulation
        for(int i=0;i<=n;i++)
            dp[i]=1;
        
        int maxSize=1,lastIndx=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                    if(maxSize<dp[i])
                    {
                        maxSize=dp[i];
                        lastIndx=i;
                    }
                }
            }
        }

        vector<int>result;
        for(int i=lastIndx;i>=0;i--)
        {
            result.push_back(nums[i]);
            maxSize--;
            if(maxSize==0)
                break;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0&&maxSize==dp[j])
                {
                    i=j+1;
                    break;
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};