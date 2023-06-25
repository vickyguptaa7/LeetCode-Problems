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
        int op1=helper(strt+1,words[strt][0]-'a',b,words,dp);
        int op2=helper(strt+1,s,words[strt].back()-'a',words,dp);
        int oper=max(op1,op2);
        if(s+'a'==words[strt].back())
        {
            oper=max(oper,op1+1);
        }
        if(b+'a'==words[strt][0])
        {
            oper=max(oper,op2+1);
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