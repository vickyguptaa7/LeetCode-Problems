class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>>result;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        helper(nums,ans,result);
        
        return result;
    }
    void helper(vector<int>nums,vector<int>ans,vector<vector<int>>&result)
    {
        if(nums.empty())
        {
            result.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i-1]==nums[i])continue;
            int val=nums[i];
            nums.erase(nums.begin()+i,nums.begin()+i+1);
            ans.push_back(val);
            helper(nums,ans,result);
            ans.pop_back();
            nums.insert(nums.begin()+i,val);
        }
    }
};