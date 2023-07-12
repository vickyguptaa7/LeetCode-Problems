class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long mn=*min_element(nums.begin(),nums.end());
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        return sum-mn*nums.size();
    }
};