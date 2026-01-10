class Solution {
    int dp[1001][1001];
public:

    int helper(int x,int y,string &s1,string &s2)
    {
        if(x>=s1.size())
        {
            int cost=0;
            for(int i=y;i<s2.size();i++)
            {
                cost+=s2[i];
            }
            return dp[x][y]=cost;
        }
        if(y>=s2.size())
        {
            int cost=0;
            for(int i=x;i<s1.size();i++)
            {
                cost+=s1[i];
            }
            return dp[x][y]=cost;
        }
        if(dp[x][y]!=-1)
            return dp[x][y];

        if(s1[x]==s2[y])
        {
            return dp[x][y] = helper(x+1,y+1,s1,s2);
        }
        else 
        {
            return dp[x][y] = min(helper(x+1,y,s1,s2)+s1[x],helper(x,y+1,s1,s2)+s2[y]);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s1,s2);
    }
};