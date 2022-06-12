class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>occr;
        int sum=0,ans=0,n=nums.size(),prev=0;
        for(int i=0;i<n;i++)
        {
            if(!occr.count(nums[i]))
            {
                occr.insert(nums[i]);
                sum+=nums[i];
            }
            else
            {
                while(occr.count(nums[i]))
                {
                    sum-=nums[prev];
                    occr.erase(nums[prev++]);
                }
                i--;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};