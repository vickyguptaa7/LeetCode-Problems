class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int total=(1<<nums.size());
        vector<vector<int>>result;
        for(int i=0;i<total;i++)
        {
            vector<int>curr;
            for(int j=0;j<nums.size();j++)
            {
                if((1<<j)&i)
                    curr.push_back(nums[j]);
            }
            result.push_back(curr);
        }
        return result;
    }
};