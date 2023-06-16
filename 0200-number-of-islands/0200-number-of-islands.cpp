class Solution
{
    public:

        vector<int> moveX = { 0,
            0,
            1,
            -1
        }, moveY = { 1,
            -1,
            0,
            0
        };

    void helper(int x, int y, vector<vector < char>> &grid, vector< vector< bool>> &visit)
    {
        visit[x][y]=true;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < 4; i++)
        {
            int _x = moveX[i] + x, _y = y + moveY[i];
            if (_x < 0 || _y < 0 || _x >= n || _y >= m || grid[_x][_y]=='0'||visit[_x][_y]) continue;
            helper(_x,_y,grid,visit);
        }
    }

    int numIslands(vector<vector < char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector < bool>> visit(n, vector<bool> (m, 0));
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '0' || visit[i][j]) continue;
                result++;
                helper(i,j,grid,visit);
            }
        }
        return result;
    }
};