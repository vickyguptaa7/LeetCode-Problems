class Solution {
public:
    
    int helper(int fuel_left,int start,int finish,vector<int>&locations,vector<vector<int>>&dp)
    {
        if(dp[start][fuel_left]!=-1)
            return dp[start][fuel_left];
        
        long long ways=0,mod=1e9+7;
        for(int i=0;i<locations.size();i++)
        {
            if(i==start||fuel_left-abs(locations[start]-locations[i])<0)continue;
            bool add=i==finish;
            ways+=add+helper(fuel_left-abs(locations[start]-locations[i]),i,finish,locations,dp);
            ways%=mod;
        }
        return dp[start][fuel_left]=ways;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) { 
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        int add=start==finish;
        return add+helper(fuel,start,finish,locations,dp);
    }
};