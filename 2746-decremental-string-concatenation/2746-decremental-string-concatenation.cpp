class Solution {
public:
    
    int helper(int strt,char s,char b,vector<string>&words,vector<vector<vector<int>>>&dp)
    {
        if(strt==words.size())
        {
            return 0;
        }
        if(dp[strt][s][b]!=-1)
            return dp[strt][s][b];
        
        int oper=max(helper(strt+1,words[strt][0]-'a',b,words,dp),helper(strt+1,s,words[strt].back()-'a',words,dp));
        if(s+'a'==words[strt].back())
        {
            oper=max(oper,helper(strt+1,words[strt][0]-'a',b,words,dp)+1);
        }
        if(b+'a'==words[strt][0])
        {
            oper=max(oper,helper(strt+1,s,words[strt].back()-'a',words,dp)+1);
        }
        return dp[strt][s][b]=oper;
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(27,vector<int>(27,-1)));
        int size=0;
        for(auto x:words)size+=x.size();
        return size-helper(1,words[0][0]-'a',words[0].back()-'a',words,dp);
    }
};