class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)return 0;
        sort(nums.begin(),nums.end());
        int low=0,high=1,res=0;
        while(low<n&&high<n)
        {
            if(low>=high)
            {
                high++;
                continue;
            }
            if(nums[high]-nums[low]==k)
            {
                res++;
                int temp=low;
                while(low<n&&nums[temp]==nums[low])low++;
                low;
                high++;
            }
            else if(nums[high]-nums[low]>k)
            {
                low++;
            }
            else
            {
                high++;
            }
        }
        return res;
    }
};