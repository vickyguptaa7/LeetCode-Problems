class Solution {
public:
    
    int helper(int iter,int prev,vector<pair<int,int>>&arr,vector<vector<int>>&dp)
    {
        if(iter==arr.size())
            return 0;
        
        if(dp[iter][prev+1]!=-1)
            return dp[iter][prev+1];
        
        int ans=0;
        if(prev==-1)
        {
            ans=max(helper(iter+1,prev,arr,dp),helper(iter+1,iter,arr,dp)+arr[iter].second);
        }
        else
        {
            if(arr[iter].second>=arr[prev].second)
            {
                ans=max(ans,helper(iter+1,iter,arr,dp)+arr[iter].second);
            }
            ans=max(ans,helper(iter+1,prev,arr,dp));
        }
        return dp[iter][prev+1]=ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>arr;
        for(int i=0;i<ages.size();i++)
        {
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return (a.first<b.first)||(a.first==b.first&&a.second<b.second);
        });

        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,arr,dp);
    }
};