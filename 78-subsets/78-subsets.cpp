class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subarray;
        vector<int>ans;
        helper(0,nums,ans,subarray);
        return subarray;
    }
    void helper(int i,vector<int>nums,vector<int>ans,vector<vector<int>>&subarray)
    {
        if(i>nums.size())return;
        if(i==nums.size())
        {
            subarray.push_back(ans);
            return;
        }
        helper(i+1,nums,ans,subarray);
        ans.push_back(nums[i]);
        helper(i+1,nums,ans,subarray);
    }
};