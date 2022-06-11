class Solution
{
    public:

        int minOperations(vector<int> &nums, int x)
        {

            int sum = accumulate(nums.begin(), nums.end(), 0);
            if(sum<x)return -1;
            int target = sum - x, n = nums.size();
            if (target == 0)
            {
                return n;
            }

            int prev = 0, res = -1;
            for (int i = 0; i < n; i++)
            {
                if (target > 0)
                {
                    target -= nums[i];
                }
                else
                {
                    if (target == 0)
                    {
                        res = max(res, i - prev);
                    }
                    target += nums[prev];
                    prev++;
                    i--;
                }
            }
            while(n>prev&&target<0)target+=nums[prev++];
            if (target == 0)
            {
                res = max(res, n - prev );
            }
            
            return res == -1 ? res : n - res;
        }
};