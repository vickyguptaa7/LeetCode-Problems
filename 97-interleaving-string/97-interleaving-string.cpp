class Solution {
public:
    bool helper(int it1,int it2,string s1,string s2,string s3,vector<vector<int>>&dp)
    {
        int it3=it1+it2;
        if(it1>=s1.size())
        {
            for(it2;it2<s2.size();it2++)
            {
                if(s2[it2]!=s3[it2+it1])return false;
            }
            return true;
        }
        if(it2>=s2.size())
        {
            for(it1;it1<s1.size();it1++)
            {
                if(s1[it1]!=s3[it2+it1])return false;
            }
            return true;
        }
        
        if(dp[it1][it2]!=-1)return dp[it1][it2];
        
        if(s1[it1]==s3[it3]&&s2[it2]==s3[it3])
        {
            return dp[it1][it2]=(helper(it1+1,it2,s1,s2,s3,dp)|helper(it1,it2+1,s1,s2,s3,dp));
        }
        else if(s1[it1]==s3[it3])
        {
            return dp[it1][it2]=helper(it1+1,it2,s1,s2,s3,dp);
        }
        else if(s2[it2]==s3[it3])
        {
            return dp[it1][it2]=helper(it1,it2+1,s1,s2,s3,dp);
        }
        else 
        {
            return dp[it1][it2]=false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        if(n+m!=s3.size())return false;
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,s1,s2,s3,dp);
    }
};