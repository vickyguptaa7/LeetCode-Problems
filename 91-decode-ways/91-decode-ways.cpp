class Solution {
public:
    
    int helper(string &str,int s,vector<int>&dp)
    {
        int n=str.size();
        
        if(n==s)
        {
            return 1;
        }
        
        if(str[s]=='0')return 0;
        
        if(dp[s]!=-1)return dp[s];
        
        if(s<n-1)
        {
            string num;
            num+=str[s];
            num+=str[s+1];
            int nm=stoi(num);
            if(nm<=26)
            {
                return dp[s]=helper(str,s+2,dp)+helper(str,s+1,dp);
            }
            else 
            {
                return dp[s]=helper(str,s+1,dp);
            }
        }
        else
        {
            return dp[s]=helper(str,s+1,dp);
        }
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        int ans=helper(s,0,dp);
        return ans;
    }
};