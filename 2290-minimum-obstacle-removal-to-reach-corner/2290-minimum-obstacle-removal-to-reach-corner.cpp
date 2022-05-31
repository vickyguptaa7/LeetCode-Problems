class Solution
{
    public:
        vector<int> moveX = { 0,
            0,
            1,
            -1
        };
    vector<int> moveY = { 1,
        -1,
        0,
        0
    };

    int minimumObstacles(vector<vector < int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector < int>> cost(rows, vector<int> (cols, 1e9));

        priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pque;
        pque.push({ 0,
            { 0,
                0 } });
        cost[0][0] = 0;

        while (!pque.empty())
        {
            int price = pque.top().first;
            int x = pque.top().second.first;
            int y = pque.top().second.second;

            pque.pop();

            if (x == rows - 1 && y == cols - 1) return price;

            for (int i = 0; i < 4; i++)
            {
                int _x = x + moveX[i], _y = y + moveY[i];

                if (_x >= rows || _x < 0 || _y < 0 || _y >= cols)
                    continue;

                if (cost[_x][_y] > price + grid[_x][_y])
                {
                    cost[_x][_y] = price + grid[_x][_y];
                    pque.push({ cost[_x][_y],
                        {
                            _x,
                            _y
                        } });
                }
            }
        }
        return cost[rows - 1][cols - 1];
    }
};