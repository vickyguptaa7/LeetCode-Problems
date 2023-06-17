class Solution {
public:
    
    int helper(int it1,vector<int>&arr1,vector<int>&arr2,map<pair<int,int>,int>&dp,int prev)
    {
        if(it1==arr1.size())
        {
            return 0;
        }
        int indx=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(indx==arr2.size()&&arr1[it1]<=prev)
            return 1e9;
        
        if(dp.count({it1,prev}))
            return dp[{it1,prev}];
        
        int ways1=1e9,ways2=1e9;
        if(arr1[it1]>prev)
        {
            ways1=min(ways1,helper(it1+1,arr1,arr2,dp,arr1[it1]));
        }

        if(indx<arr2.size())
        {
            ways2=min(ways2,helper(it1+1,arr1,arr2,dp,arr2[indx])+1);
        }
        return dp[{it1,prev}]=min(ways1,ways2);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int>dp;
        int cost=helper(0,arr1,arr2,dp,-1);
        return cost==1e9?-1:cost;
    }
};