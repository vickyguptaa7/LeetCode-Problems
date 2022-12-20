class Solution
{
    public:

        int isValid(vector<int> &stones, int mid, vector<int> &visit)
        {
            if (mid == 0)
            {
                return stones.front() == stones.back();
            }
            int val = 0, n = stones.size();
            for (auto &x: visit)
                x = false;

            while (val != n)
            {
                int indx = lower_bound(stones.begin(), stones.end(), mid + stones[val]) - stones.begin();
                if (indx != n && stones[indx] - stones[val] > mid)
                {
                    indx--;
                }
                if (indx == val)
                    return false;
                val = indx;
                if (val != n)
                    visit[val] = true;
            }
            visit.back() = false;
            int prev = stones[0];
            for (int i = 1; i < n; i++)
            {
                if (!visit[i])
                {
                    if (mid < stones[i] - prev)
                        return false;
                    prev = stones[i];
                }
            }
            return true;
        }
    int maxJump(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> visit(n, false);
        int low = 0, high = stones.back();
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isValid(stones, mid, visit))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};