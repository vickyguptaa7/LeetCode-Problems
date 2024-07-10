class Solution {
    vector<vector<int>>presum;
public:
    
    int rangeAnd(int l,int r)
    {
        int res=0;
        for(int i=0;i<31;i++)
        {
            int count=presum[r+1][i]-presum[l][i];
            if(count==r-l+1)
            {
                
                res=(res|(1<<i));
            }
        }
        return res;
    }
    
    int helper1(int val,int k,int strt,int end,vector<int>&nums)
    {
        int init=strt;
        int res=end+1;
        while(strt<=end)
        {
            int mid=(strt+end)/2;
            if(rangeAnd(init,mid)>k)
            {
                strt=mid+1;
            }
            else
            {
                end=mid-1;
                res=mid;
            }
        }
        return res;
    }
    
    int helper2(int val,int k,int strt,int end,vector<int>&nums)
    {
        int init=strt;
        int res=end+1;
        while(strt<=end)
        {
            int mid=(strt+end)/2;
            if(rangeAnd(init,mid)>=k)
            {
                res=mid;
                strt=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        presum.resize(nums.size()+1,vector<int>(31,0));
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<31;j++)
            {
                presum[i+1][j]+=presum[i][j]+!!(nums[i]&(1<<j));
            }
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&k)!=k)continue;
            int left=helper1(nums[i],k,i,n-1,nums);
            int right=helper2(nums[i],k,i,n-1,nums);
            ans+=(right-left+1);
        }
        return ans;
    }
};