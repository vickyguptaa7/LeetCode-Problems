class Solution
{
    public:
        vector<string> summaryRanges(vector<int> &nums)
        {
            int prev = 0, n = nums.size();
            if(!n)return {};
            vector<string> result;
            for (int i = 1; i < n; i++)
            {
                if (nums[i] != nums[i - 1] + 1)
                {
                    if (prev == i - 1)
                        result.push_back(to_string(nums[prev]));
                    else
                        result.push_back(to_string(nums[prev]) + "->" + to_string(nums[i - 1]));
                    prev = i;
                }
            }
            if (prev == n - 1)
                result.push_back(to_string(nums[prev]));
            else
                result.push_back(to_string(nums[prev]) + "->" + to_string(nums[n - 1]));
            return result;
        }
};