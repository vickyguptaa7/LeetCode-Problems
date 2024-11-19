class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int>ump(1e5+5,0);
        int n=nums.size();
        long long sum=0,ans=0,cntr=0;
        for(int i=0;i<n;i++)
        {
            if(ump[nums[i]]==1)
                cntr++;
            sum+=nums[i];
            ump[nums[i]]++;
            if(i+1>=k)
            {
                if(!cntr)
                {
                    ans=max(ans,sum);
                }
                ump[nums[i+1-k]]--;
                if(ump[nums[i+1-k]]==1)
                {
                    cntr--;
                }
                sum-=nums[i+1-k];
            }
        }
        return ans;
    }
};