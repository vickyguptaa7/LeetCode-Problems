class Solution {
public:
    
    int helper(int strt,string s,set<string>&dictionary,vector<int>&dp)
    {
        if(strt==s.size())
        {
            return 0;
        }
        if(dp[strt]!=-1)
            return dp[strt];
        string word;
        int minEx=1+helper(strt+1,s,dictionary,dp);
        for(int i=strt;i<s.size();i++)
        {
            word+=s[i];
            if(dictionary.count(word))
            {
                minEx=min(minEx,helper(i+1,s,dictionary,dp));
            }
        }
        
        return dp[strt]=minEx;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>oset;
        vector<int>dp(s.size(),-1);
        for(auto dict:dictionary)
            oset.insert(dict);
        return helper(0,s,oset,dp);
    }
};