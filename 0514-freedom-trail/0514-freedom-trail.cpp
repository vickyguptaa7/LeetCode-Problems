class Solution {
    vector<vector<int>>dp;
public:
    
    int helper(int level,int prev,string &ring,string &key)
    {
        if(level==key.size())
            return 0;
        
        if(dp[level][prev]!=-1)
            return dp[level][prev];
        
        int mn=1e9,n=ring.size();
        for(int i=0;i<n;i++)
        {
            if(key[level]!=ring[i])continue;
            mn=min(mn,min({abs(i-prev),(prev+n-i),n-prev+i})+1+helper(level+1,i,ring,key));
        }
        return dp[level][prev]=mn;
    }
    
    int findRotateSteps(string ring, string key) {
        dp.resize(key.size(),vector<int>(ring.size(),-1));
        return helper(0,0,ring,key);
    }
};