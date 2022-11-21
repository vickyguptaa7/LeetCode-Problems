class Solution {
public:
    vector<int>prime={2,3,5,7};
    bool isPrime(char ch)
    {
        for(auto x:prime)
        {
            if(ch-'0'==x)
            {
                return true;
            }
        }
        return false;
    }
    int helper(int s,int n,int k,int mL,string &str,vector<vector<long long>>&dp)
    {
        if(k==0&&s<=n)return 1;
        
        if(s>=n)return 0;
        
        if(dp[s][k]!=-1)
            return dp[s][k];
        
        long long ways=helper(s+1,n,k,mL,str,dp),mod=1e9+7;
        
        if(!isPrime(str[s-1])&&(isPrime(str[s])))
        {
            ways+=helper(s+mL,n,k-1,mL,str,dp);
            ways%=mod;
        }
        
        return dp[s][k]=ways%mod;
    }
    
    int beautifulPartitions(string s, int k, int minLength) {
        int n=s.size();
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        if(!isPrime(s[0])||isPrime(s.back()))
            return false;
        return helper(minLength,n,k-1,minLength,s,dp);
    }
};