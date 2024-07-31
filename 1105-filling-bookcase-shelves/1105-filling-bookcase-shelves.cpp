class Solution {
public:
    
    int helper(int indx,int sw,vector<vector<int>>&books,vector<int>&dp)
    {
        if(indx>=books.size())
            return 0;
        if(dp[indx]!=-1)
            return dp[indx];
        int ans=1e9;
        int mx=0,w=0;
        for(int i=indx;i<books.size();i++)
        {
            if(sw<w+books[i][0])
            {
                break;
            }
            mx=max(mx,books[i][1]);
            w+=books[i][0];
            ans=min(ans,helper(i+1,sw,books,dp)+mx);
        }
        return dp[indx]=ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n+1,-1);
        return helper(0,shelfWidth,books,dp);
    }
};