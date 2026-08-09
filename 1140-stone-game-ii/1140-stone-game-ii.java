class Solution {

    private int helper(int lvl,int m, boolean isAlice, int[] piles, int[][][] dp)
    {
        if(lvl>=piles.length)
            return 0;
        if(dp[isAlice?0:1][lvl][m]!=-1)
            return dp[isAlice?0:1][lvl][m];
        
        int res=isAlice?0:1000000000,sum=0;
        for(int i=lvl;i<Math.min(piles.length,lvl+2*m);i++)
        {
            sum+=piles[i];
            if(isAlice)
            {
                res = Math.max(res,sum+helper(i+1,Math.max(m,i-lvl+1),!isAlice,piles,dp));
            }
            else
            {
                res = Math.min(res,helper(i+1,Math.max(m,i-lvl+1),!isAlice,piles,dp));
            }
        }
        return  dp[isAlice?0:1][lvl][m]=res;
    }

    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[][][] dp = new int[2][n][200];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 200; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return helper(0, 1, true, piles, dp);
    }
}