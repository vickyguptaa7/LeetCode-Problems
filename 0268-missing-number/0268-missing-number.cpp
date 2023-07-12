class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0ll);
        int n=nums.size();
        return (n*(n+1)/2)-sum;
    }
};