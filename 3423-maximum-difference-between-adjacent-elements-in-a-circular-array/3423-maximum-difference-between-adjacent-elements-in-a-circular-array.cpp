class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res=max(abs(nums.front()-nums.back()),abs(nums.back()-nums.front()));
        for(int i=1;i<nums.size();i++)
        {
            res=max({res,abs(nums[i]-nums[i-1]),abs(nums[i-1]-nums[i])});
        }
        return res;
    }
};