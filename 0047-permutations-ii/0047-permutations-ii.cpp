class Solution {
public:
    
    void helper(vector<int>&nums,vector<int>&curr,vector<vector<int>>&perm)
    {
        if(nums.empty())
        {
            perm.push_back(curr);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i]==nums[i-1])continue;
            curr.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            helper(nums,curr,perm);
            nums.insert(nums.begin()+i,curr.back());
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>perm;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        helper(nums,curr,perm);
        return perm;
    }
};