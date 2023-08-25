class Solution {
    int dp[100][100];
public:
    
    bool helper(int indx1,int indx2,string &s1,string &s2,string &s3)
    {
        if(indx1==s1.size())
        {
            for(int i=indx2;i<s2.size();i++)
            {
                if(s2[i]!=s3[indx1+i])
                    return false;
            }
            return true;
        }
        if(indx2==s2.size())
        {
            for(int i=indx1;i<s1.size();i++)
            {
                if(s1[i]!=s3[indx2+i])
                    return false;
            }
            return true;
        }
        
        if(dp[indx1][indx2]!=-1)
            return dp[indx1][indx2];
        
        bool isPossible=false;
        
        if(s1[indx1]==s3[indx1+indx2])
            isPossible|=helper(indx1+1,indx2,s1,s2,s3);
        
        if(s2[indx2]==s3[indx1+indx2])
            isPossible|=helper(indx1,indx2+1,s1,s2,s3);
        
        return dp[indx1][indx2]=isPossible;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s1,s2,s3);
    }
};