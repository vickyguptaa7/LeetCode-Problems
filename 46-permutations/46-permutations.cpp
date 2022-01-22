class Solution {
public:
    void helper(vector<int>nums,vector<int>ans,vector<vector<int>>&list)
    {
        if(nums.empty())
        {
            list.push_back(ans);
            return;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            helper(nums,ans,list);
            nums.insert(i+nums.begin(),ans[ans.size()-1]);
            ans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans_list;
        vector<int>ans;
        helper(nums,ans,ans_list);
        return ans_list;
    }
};