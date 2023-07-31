class Solution {
public:
    
    int asciiSum(int strt,string &s)
    {
        int sum=0;
        for(int i=strt;i<s.size();i++)
            sum+=s[i];
        return sum;
    }
    
    int helper(int indx1,int indx2,string &s1,string& s2,vector<vector<int>>&dp)
    {
        if(indx1==s1.size())
        {
            return asciiSum(indx2,s2);
        }
        if(indx2==s2.size())
        {
            return asciiSum(indx1,s1);
        }
        
        if(dp[indx1][indx2]!=-1)
            return dp[indx1][indx2];
        
        if(s1[indx1]==s2[indx2])
        {
            return dp[indx1][indx2]=helper(indx1+1,indx2+1,s1,s2,dp);
        }
        else
        {
            return dp[indx1][indx2]=min(helper(indx1+1,indx2,s1,s2,dp)+s1[indx1],
                       helper(indx1,indx2+1,s1,s2,dp)+s2[indx2]);
        }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(0,0,s1,s2,dp);
    }
};