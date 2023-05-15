class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        long long mod=1e9+7,n=nums.size(),calc=0;
        vector<long long>preSum(n+1,0);
        for(int i=0;i<n;i++)
        {
            preSum[i+1]=(preSum[i]*2ll+nums[i])%mod;
        }
        for(int i=0;i<n;i++)
        {
            if(i>=2)
                calc+=preSum[i-1];
            calc+=nums[i];
            calc%=mod;
            sum=((sum)%mod+(calc*(((long long)nums[i])%mod*((long long)nums[i])%mod)%mod)%mod)%mod;
        }
        return sum;
    }
};