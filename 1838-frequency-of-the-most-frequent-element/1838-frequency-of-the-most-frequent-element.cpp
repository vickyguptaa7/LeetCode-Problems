class Solution {
public:
    
    int helper(int l,int h,int k,vector<long long>&presum,vector<int>&nums)
    {
        int indx=h,last=h;
        while(l<=h)
        {
            int mid=(l+h)/2;
            long long sum=presum[last]-presum[mid];
            long long oper=nums[last]*1ll*(last-mid)-sum;
            if(oper<=k)
            {
                indx=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return indx;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int res=1;
        sort(nums.begin(),nums.end());
        vector<long long>presum(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            presum[i]+=presum[i-1]+nums[i-1];
        }
        for(int i=1;i<nums.size();i++)
        {
            int indx=helper(0,i,k,presum,nums);
            res=max(res,i-indx+1);
        }
        return res;
    }
};