class Solution {
public:
    
    bool check(long long num,int k,vector<int>&nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            int indx=upper_bound(nums.begin(),nums.end(),num+nums[i])-nums.begin();
            k-=max(0,indx-i-1);
        }
        return k>0;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        long long l=0,h=1e13;
        long long ans=0;
        sort(nums.begin(),nums.end());
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(check(mid,k,nums))
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
};