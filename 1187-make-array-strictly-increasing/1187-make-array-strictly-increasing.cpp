class Solution {
public:
    
    int helper(int it1,vector<int>&arr1,vector<int>&arr2,map<int,int>dp[],int prev)
    {
        if(it1==arr1.size())
        {
            return 0;
        }
        int indx=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(indx==arr2.size()&&arr1[it1]<=prev)
            return 1e9;
        
        if(dp[it1].count(prev))
            return dp[it1][prev];
        
        int ways=1e9;
        if(arr1[it1]>prev)
        {
            ways=min(ways,helper(it1+1,arr1,arr2,dp,arr1[it1]));
        }

        if(indx<arr2.size())
        {
            ways=min(ways,helper(it1+1,arr1,arr2,dp,arr2[indx])+1);
        }
        return dp[it1][prev]=ways;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<int,int>dp[arr1.size()+1];
        int cost=helper(0,arr1,arr2,dp,-1);
        return cost==1e9?-1:cost;
    }
};