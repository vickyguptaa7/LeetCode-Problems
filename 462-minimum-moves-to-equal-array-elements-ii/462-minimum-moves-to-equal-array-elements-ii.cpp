class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target=nums[nums.size()/2];
        int res=0;
        for(auto x:nums)
        {
            res+=abs(x-target);
        }
        return res;
    }
};