class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long ans=arr.size(),n=arr.size(),mod=1e9+7;
        vector<long long>dp(n,1);
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int find=arr[i]/arr[j];
                    int indx=lower_bound(arr.begin(),arr.end(),find)-arr.begin();
                    if(arr[j]*(long long)arr[indx]==arr[i])
                    {
                        dp[i]+=(dp[j]*dp[indx])%mod;
                    }
                }
            }
        }
        ans=accumulate(dp.begin(),dp.end(),0ll);
        return ans%mod;
    }
};