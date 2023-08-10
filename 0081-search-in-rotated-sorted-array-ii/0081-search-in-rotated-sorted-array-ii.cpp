class Solution
{
    public:
        bool search(vector<int> &nums, int target)
        {
            int low = 0, high = nums.size() - 1;
            while (low <= high)
            {
                
                while (low < high && nums[low + 1] == nums[low])
                {
                    low++;
                }
                
                while (low < high && nums[high - 1] == nums[high])
                {
                    high--;
                }
                
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                    return true;
                if (nums[mid] >= nums.front())
                {
                    if (target >= nums.front() && nums[mid] >= target)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (target <= nums.back() && nums[mid] <= target)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            return false;
        }
};