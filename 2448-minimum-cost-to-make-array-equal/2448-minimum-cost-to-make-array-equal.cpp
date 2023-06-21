class Solution {
public:
    
    long long check(int k,vector<int>&nums,vector<int>&cost)
    {
        long long curr=0;
        for(int i=0;i<nums.size();i++)
        {
            curr+=cost[i]*1LL*abs(k-nums[i]);
        }
        return curr;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        long long res=0,pcost=1e18;
        while(l<=h)
        {
            int mid1=(l+h)/2;
            int mid2=mid1+1;
            long long c1=check(mid1,nums,cost);
            long long c2=check(mid2,nums,cost);
            if(pcost>=c1)
            {
                pcost=c1;
                res=mid1;
            }
            if(pcost>=c2) 
            {
                pcost=c2;
                res=mid2;
            }
            if(c1<=c2)
            {
                h=mid1-1;
            }
            else
            {
                l=mid2+1;
            }
        }
        return check(res,nums,cost);
    }
};