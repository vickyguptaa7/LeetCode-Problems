class Solution {
public:
    
    int helper(int strt,string &num,int count,bool restrict,
               vector<vector<vector<int>>>&dp)
    {
        if(strt==num.size())
            return count;
        if(dp[strt][count][restrict]!=-1)
            return dp[strt][count][restrict];
        
        int end=(restrict)?num[strt]-'0':10;
        int res=0;
        for(int i=0;i<end;i++)
        {
            res+=helper(strt+1,num,count+(i==1),false,dp);
        }
        if(restrict)
            res+=helper(strt+1,num,count+(end==1),true,dp);
        return dp[strt][count][restrict]=res;
    }
    int countDigitOne(int n) {
        string num=to_string(n);
        vector<vector<vector<int>>>dp(num.size(),
                                      vector<vector<int>>(10,vector<int>(2,-1)));
        return helper(0,num,0,true,dp);
    }
};