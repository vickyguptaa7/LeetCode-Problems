class Solution
{
    public:
        long long putMarbles(vector<int> &weights, int k)
        {
            priority_queue<int> pque1;
            priority_queue<int, vector < int>, greater < int>> pque2;
            for (int i = 1; i < weights.size(); i++)
            {
                pque1.push(weights[i - 1] + weights[i]);
                pque2.push(weights[i - 1] + weights[i]);
                if (pque1.size() == k) {
                    pque1.pop();
                    pque2.pop();
                }
            }
            long long ans = 0;
            while (!pque1.empty())
            {
                ans += pque2.top() - pque1.top() + 0ll;
                pque1.pop();
                pque2.pop();
            }
            return ans;
        }
};