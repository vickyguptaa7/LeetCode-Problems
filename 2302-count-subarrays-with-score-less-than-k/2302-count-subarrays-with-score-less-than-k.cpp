class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result=0;
        int n=nums.size(),prev=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(prev<n&&sum*(i-prev+1)>=k)
            {
                sum-=nums[prev++];
            }
            result+=i-prev+1;
        }
        return result;
    }
};