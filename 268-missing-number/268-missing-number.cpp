class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int sumn=(nums.size()+1)*nums.size()/2;
        int ans=sumn-sum;
        return ans;
    }
};