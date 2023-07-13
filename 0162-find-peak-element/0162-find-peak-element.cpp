class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long curr=nums[mid];
            long prev=(mid==0)?-1e12:nums[mid-1];
            long next=(mid==n-1)?-1e12:nums[mid+1];
            if(curr>prev&&curr>next)
            {
                return mid;
            }
            else if(curr<prev)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return 0;
    }
};