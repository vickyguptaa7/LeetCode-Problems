class Solution {
public:
    int kadaneAlgo(vector<int>&arr)
    {
        int sum=0,maxSum=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            maxSum=max(maxSum,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxSum;
    }
    int helper(vector<int>&arr,vector<int>&brr)
    {
        vector<int>diff;
        for(int i=0;i<arr.size();i++)
        {
            diff.push_back(arr[i]-brr[i]);
        }
        int result=accumulate(brr.begin(),brr.end(),0)+kadaneAlgo(diff);
        return result;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(helper(nums1,nums2),helper(nums2,nums1));
    }
};