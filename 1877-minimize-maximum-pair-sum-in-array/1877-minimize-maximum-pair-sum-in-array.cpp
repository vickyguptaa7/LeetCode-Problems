class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            maxSum=max(maxSum,nums[i]+nums[n-1-i]);
        }
        return maxSum;
    }
};