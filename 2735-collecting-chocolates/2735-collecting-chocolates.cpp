class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<long long>ncost(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ncost[j]=min(ncost[j],(long long)nums[((j-i)%n+n)%n]);
            }
            sum=min(sum,accumulate(ncost.begin(),ncost.end(),0ll)+i*1ll*x);
        }
        return sum;
    }
};