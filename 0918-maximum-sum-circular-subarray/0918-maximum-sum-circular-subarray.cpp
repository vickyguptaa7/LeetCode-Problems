class Solution {
public:
    int maxSumSubarray(vector<int>&arr)
    {
        int sum=0,Max=arr[0];
        for(auto x:arr)
        {
            sum+=x;
            Max=max(sum,Max);
            if(sum<0)sum=0;
        }
        return Max;
    }
    int minSumSubarray(vector<int>&arr)
    {
        int sum=0,Min=arr[0];
        for(auto x:arr)
        {
            sum+=x;
            Min=min(sum,Min);
            if(sum>0)sum=0;
        }
        return Min;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int minSum=minSumSubarray(nums);
        int maxSum=maxSumSubarray(nums);
        // cout<<total<<" "<<minSum<<"\n";
        return maxSum>0?max(maxSum,total-minSum):maxSum;
    }
};