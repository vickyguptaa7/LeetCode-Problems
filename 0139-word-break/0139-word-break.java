class Solution {

    private boolean helper(int lvl, String s, Set<String> st,int[] dp)
    {
        if(lvl==s.length())
        {
            return true;
        }
        if(dp[lvl]!=-1)
        {
            return dp[lvl]==1;
        }
        StringBuilder temp = new StringBuilder();
        for(int i=lvl;i<Math.min(s.length(),lvl+20);i++)
        {
            temp.append(s.charAt(i));
            if(st.contains(temp.toString()) && helper(i+1,s,st,dp))
            {
                dp[lvl]=1;
                return true;
            }
        }
        dp[lvl]=0;
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        int[] dp = new int[s.length()];
        for(int i=0;i<s.length();i++)dp[i]=-1;
        Set<String> st = new HashSet<>(wordDict);
        return helper(0,s,st,dp);
    }
}