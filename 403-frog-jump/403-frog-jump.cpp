class Solution {
public:
    bool helper(int prev,int idx,vector<int>&stones,vector<vector<int>>&dp)
    {
        if(idx>=stones.size()-1)return dp[prev][idx]=1;
        
        if(dp[prev][idx]!=-1)return dp[prev][idx];
        // cout<<idx<<"\n";
        int move1=stones[idx]+prev-1,move2=stones[idx]+prev,move3=stones[idx]+prev+1;
        int ans=false;
        for(int i=idx+1;i<stones.size();i++)
        {
            if(stones[i]==move1)
            {
                ans=(ans|helper(prev-1,i,stones,dp));
            }
            else if(stones[i]==move2)
            {
                ans=(ans|helper(prev,i,stones,dp));
            }
            else if(stones[i]==move3)
            {
                ans=(ans|helper(prev+1,i,stones,dp));
            }
            if(ans)return dp[prev][idx]=1;
            if(stones[i]>=move3)break;
          
        }
        return  dp[prev][idx]=0;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(1001,(vector<int>(stones.size()+1,-1)));
        return helper(0,0,stones,dp);
    }
};