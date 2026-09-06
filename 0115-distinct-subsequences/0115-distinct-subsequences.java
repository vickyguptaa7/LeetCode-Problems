class Solution {

    int helper(int l1,int l2,String s,String t,int[][]dp)
    {
        int sn = s.length(),tn=t.length();
        if(l2>=tn)
            return 1;
        if(l1>=sn)
            return 0;
        if(dp[l1][l2]!=-1)
            return dp[l1][l2];
        
        int res=0;
        if(s.charAt(l1)==t.charAt(l2))
            res = helper(l1+1,l2+1,s,t,dp);
        
        res+=helper(l1+1,l2,s,t,dp);
    
        return dp[l1][l2]=res;
    }

    public int numDistinct(String s, String t) {
        int sn = s.length(),tn=t.length();
        int[][] dp = new int[sn+1][tn+1];
        for(int i=0;i<sn;i++)
        {
            for(int j=0;j<tn;j++)
                dp[i][j] = -1;
        }
        return helper(0,0,s,t,dp);
    }
}