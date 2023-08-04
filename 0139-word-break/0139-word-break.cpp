class Solution {
    
    bool helper(int indx,string &s,unordered_set<string>&dict,vector<int>&dp)
    {
        if(indx==s.size())
            return 1;
        if(dp[indx]!=-1)
            return dp[indx];
        string word;
        for(int i=indx;i<s.size();i++)
        {
            word+=s[i];
            if(dict.count(word)&&helper(i+1,s,dict,dp))
            {
                return true;
            }
        }
        return dp[indx]=false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
       
        for(auto &word:wordDict)
            dict.insert(word);
        vector<int>dp(s.size(),-1); 
        return helper(0,s,dict,dp);
    }
};