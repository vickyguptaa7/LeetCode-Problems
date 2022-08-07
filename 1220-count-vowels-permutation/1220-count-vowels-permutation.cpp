class Solution {
public:
    
    int helper(char src,int s,int n,map<char,vector<char>>&list,vector<vector<int>>&dp)
    {
        if(n==s)return 1;
        
        if(dp[s][src-'a']!=-1)
            return dp[s][src-'a'];
        
        long long ways=0,mod=1e9+7;
        for(auto x:list[src])
        {
            ways+=helper(x,s+1,n,list,dp);
            ways%=mod;
        }
        return dp[s][src-'a']=ways;
    }
    int countVowelPermutation(int n) {
        map<char,vector<char>>list;
        list['a'].push_back('e');
        
        list['e'].push_back('a');
        list['e'].push_back('i');
        
        list['i'].push_back('a');
        list['i'].push_back('e');
        list['i'].push_back('o');
        list['i'].push_back('u');
        
        list['o'].push_back('i');
        list['o'].push_back('u');
        
        list['u'].push_back('a');
        
        if(n==1)
            return 5;
        
        vector<vector<int>>dp(n+1,vector<int>(27,-1));
        
        vector<char>crr={'a','e','i','o','u'};
        long long ways=0,mod=1e9+7;
        for(int i=0;i<5;i++)
        {
            ways+=helper(crr[i],1,n,list,dp);
            ways=ways%mod;
        }
        return ways;
    }
};