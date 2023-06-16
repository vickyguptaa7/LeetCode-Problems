class Solution {
public:
    
    int helper(vector<int>nums,vector<vector<int>>&pascal)
    {
        if(nums.size()<=2)
            return 1;
        int n=nums.size(),mod=1e9+7;
        vector<int>left,right;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[0])left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int ls=left.size(),rs=right.size();
        return (((helper(left,pascal)%mod)*1ll*(pascal[n-1][ls])%mod)*1ll*(helper(right,pascal)%mod))%mod;
        
    }
    
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>pascal(n+1);
        int mod=1e9+7;
        for(int i=0;i<=n;i++)
        {
            pascal[i].resize(i+1,1);
            for(int j=1;j<i;j++)
            {
                pascal[i][j]=(pascal[i-1][j]%mod+pascal[i-1][j-1]%mod)%mod;
            }
        }
        return helper(nums,pascal)-1;
    }
};