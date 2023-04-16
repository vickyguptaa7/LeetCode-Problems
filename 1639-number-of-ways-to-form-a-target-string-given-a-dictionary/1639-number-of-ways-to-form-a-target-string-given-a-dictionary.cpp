class Solution {
public:
    
    int helper(int start,int iter,string &target,vector<vector<int>>&indxFreq,
              vector<vector<long long>>&dp)
    {
        if(iter==target.size())
            return 1;
        if(start==indxFreq.size())
            return 0;
        if(dp[start][iter]!=-1)
            return dp[start][iter];
        
        long long ways=0,mod=1e9+7ll;
        
        if(indxFreq[start][target[iter]-'a'])
        {
            ways+=(long long)indxFreq[start][target[iter]-'a']*
                helper(start+1,iter+1,target,indxFreq,dp)+
                helper(start+1,iter,target,indxFreq,dp);
        }
        else
        {
            ways+=helper(start+1,iter,target,indxFreq,dp);
        }
        return dp[start][iter]=ways%mod;
    }
    
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>indxFreq(words[0].size(),vector<int>(26,0));
        for(auto word:words)
        {
            for(int i=0;i<word.size();i++)
            {
                indxFreq[i][word[i]-'a']++;
            }
        }
        vector<vector<long long>>dp(words[0].size(),vector<long long>(target.size(),-1));
        return helper(0,0,target,indxFreq,dp);
    }
};