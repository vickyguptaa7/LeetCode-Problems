class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int x=0,y=n-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
                break;
            x=i;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>=nums[i+1])
                break;
            y=i;
        }
        if(y<=x)
        {
            return n*(n+1ll)/2;
        }
        long long sum=x+1+(n-y)+1;
        int left=0,right=y;
        while(left<=x&&right<n)
        {
            if(nums[left]>=nums[right])
            {
                right++;
                continue;
            }
            left++;
            sum+=n-right;
        }
        return sum;
    }
};