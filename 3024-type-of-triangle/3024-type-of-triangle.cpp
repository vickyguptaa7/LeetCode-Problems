class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]<=nums[2]||nums[1]+nums[2]<=nums[0]||nums[0]+nums[2]<=nums[1])
            return "none";
        if(nums[0]==nums[1]&&nums[1]==nums[2])
            return "equilateral";
        
        return (nums[1]==nums[0]||nums[1]==nums[2]||nums[0]==nums[2])?"isosceles":"scalene";
    }
};