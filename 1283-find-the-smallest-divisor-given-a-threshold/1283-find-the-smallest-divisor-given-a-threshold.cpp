class Solution {
public:
    
    int calcValue(vector<int>&nums,int divisor)
    {
        int val=0;
        for(auto x:nums)
        {
            val+=ceil(x/(double)divisor);
        }
        return val;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end()),divisor=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(calcValue(nums,mid)<=threshold)
            {
                high=mid-1;
                divisor=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return divisor;
    }
};