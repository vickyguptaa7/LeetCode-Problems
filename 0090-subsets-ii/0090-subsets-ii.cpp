class Solution
{
    public:

        void helper(int strt, vector<int> &nums, vector<int> &subset, vector< vector< int>> &subsets)
        {
            subsets.push_back(subset);
            for (int i = strt; i < nums.size(); i++)
            {
                if(strt!=i&&nums[i]==nums[i-1])continue;
                subset.push_back(nums[i]);
                helper(i + 1, nums, subset, subsets);
                subset.pop_back();
            }
        }

    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector < int>> subsets;
        vector<int> subset;
        helper(0, nums, subset, subsets);
        return subsets;
    }
};