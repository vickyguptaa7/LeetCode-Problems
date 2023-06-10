class Solution
{
    public:

        bool check(int mid, int indx, int n, long long maxSum)
        {
            long long left = indx, right = n - indx - 1;
            if (left < mid)
            {
                int rem = mid - left - 1;
                maxSum += rem *(rem + 1ll) / 2;
                maxSum -= mid *(mid + 1ll) / 2;
            }
            else
            {
                maxSum -= mid *(mid + 1ll) / 2;
                maxSum -= (left - mid + 1ll);
            }
            if (maxSum < 0)
                return false;
            
            if (right < mid)
            {
                int rem = mid - right-1;
                maxSum += rem *(rem + 1ll) / 2;
                if (maxSum < 0)
                    return false;
                maxSum -= mid *(mid - 1ll) / 2;
            }
            else
            {
                maxSum -= mid *(mid - 1ll) / 2;
                if (maxSum < 0)
                    return false;
                maxSum -= (right - mid+1);
            }
            return maxSum >= 0;
        }

    int maxValue(int n, int index, int maxSum)
    {
        int low = 1, high = maxSum, ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(mid, index, n, maxSum))
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};