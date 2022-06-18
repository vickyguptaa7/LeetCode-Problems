class Solution {
public:
    bool Check(vector<int>&nums,int mid,int m)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                sum=nums[i];
                if(sum>mid)return false;
                m--;
            }
        }
        if(m<=0)return false;
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        long long low=0,high=1e9;
        int ans=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(Check(nums,mid,m))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};