class Solution {
public:
    
    int helper(int strt,char prev,int count,int k,string &s,vector<vector<vector<vector<int>>>>&dp)
    {
        if(k<0)return 1e9;
        if(strt==s.size())
        {
            return 0;
        }
        if(dp[strt][k][prev][count]!=-1)
            return dp[strt][k][prev][count];
        if(prev==s[strt]-'a')
        {
            int ways=0;
            if(count+1==2||count+1==10||count+1==100)ways=1;
            
            return dp[strt][k][prev][count]=min(helper(strt+1,prev,count,k-1,s,dp),
                                helper(strt+1,prev,count+1,k,s,dp)+ways);
        }
        else
        {
            return dp[strt][k][prev][count]=min(helper(strt+1,prev,count,k-1,s,dp),
                                   helper(strt+1,s[strt]-'a',1,k,s,dp)+1);
        }
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<vector<vector<int>>>>dp
            (s.size()+1,vector<vector<vector<int>>>
             (k+1,vector<vector<int>>(27,vector<int>(100,-1))));
        return helper(0,'{'-'a',0,k,s,dp);
    }
};