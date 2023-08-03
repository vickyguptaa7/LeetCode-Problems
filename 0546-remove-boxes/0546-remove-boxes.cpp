class Solution
{
    public:

        int helper(int start, int end, int count, vector<int> &boxes
                  ,vector<vector<vector<int>>>&dp)
        {
            if (start >= end)
                return start == end ? (count+1)*(count+1) : 0;
            
            if(dp[start][end][count]!=-1)
                return dp[start][end][count];
            
            int initStart=start;
            
            int leftCnt = 1 + count;
            
            while (start + 1 <= end && boxes[start] == boxes[start + 1])
            {
                start++;
                leftCnt++;
            }

            int maxVal = leftCnt*leftCnt + helper(start + 1, end, 0, boxes,dp);

            for (int i = start + 1; i <= end; i++)
            {
                if (boxes[i] == boxes[start])
                {
                    maxVal = max(maxVal, helper(i, end, leftCnt, boxes,dp) +
                        helper(start + 1, i - 1, 0, boxes,dp));
                }
            }
            return dp[initStart][end][count]=maxVal;
        }

    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return helper(0, n - 1, 0, boxes,dp);
    }
};