class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> result(n, 0);
            int zc = 0, mult = 1;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0) zc++;
                else mult *= nums[i];
            }
            if (zc > 1) 
                return result;
            else if (zc == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (nums[i] == 0)
                    {
                        result[i]=mult;
                        break;
                    }                       
                }
            }
            else 
            {
                for (int i = 0; i < n; i++)
                {
                        result[i]=mult/nums[i];
                }
            }
            return result;
        }
};