class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=-1,right=-1,n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                left=i-1;
                break;
            }
        }
        if(left==-1)
            return 0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]<nums[i])
            {
                right=i+1;
                break;
            }
        }
        int Min=nums[left],Max=nums[right];
        for(int i=left;i<=right;i++)
        {
            if(Min>nums[i])
            {
                Min=nums[i];
            }
            if(Max<nums[i])
            {
                Max=nums[i];
            }
        }
        while(left>=0&&nums[left]>Min)
        {
            left--;
        }
        while(right<n&&nums[right]<Max)
        {
            right++;
        }
        return right-left-1;
    }
};