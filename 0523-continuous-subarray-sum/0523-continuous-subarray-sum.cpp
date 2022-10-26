class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<long long>preSum(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            preSum[i]=preSum[i-1]+nums[i-1];
        }
        unordered_map<int,int>mmp;
        int sum=nums[0]%k;
        mmp[sum]=0;
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            sum%=k;
            if(mmp.count(sum))
            {
                if(i-mmp[sum]!=1)
                    return true;
            }
            else
                mmp[sum]=i;
            if(sum==0)
            {
                return true;
            }
        }
        return false;
    }
};