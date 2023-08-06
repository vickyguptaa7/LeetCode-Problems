class Solution {
public:
    
    int helper(int curr,int newSong,int goal,int k,int n,vector<vector<int>>&dp)
    {
        if(curr==goal)
            return newSong==0;
        if(newSong<0)
            return 0;
        if(dp[curr][newSong]!=-1)
            return dp[curr][newSong];
            
        int mod=1e9+7;
        int takeNewSong=(helper(curr+1,newSong-1,goal,k,n,dp)*1ll*(newSong))%mod;
        int takeOldSong=(helper(curr+1,newSong,goal,k,n,dp)*1ll*(max(0,n-newSong-k)))%mod;
        
        return dp[curr][newSong]=(takeNewSong+takeOldSong)%mod;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(goal,vector<int>(n+1,-1));
        return helper(0,n,goal,k,n,dp);
    }
};