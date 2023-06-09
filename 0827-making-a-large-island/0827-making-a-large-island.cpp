class Solution
{
    public:
        vector<int> moveX = { 1,
            -1,
            0,
            0
        }, moveY = { 0,
            0,
            1,
            -1
        };

    void markIsland(int x, int y, int &cntr, vector<vector < int>> &grid, vector< vector< int>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        visited[x][y] = cntr;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= m || _x < 0 || _y < 0 || !grid[_x][_y] || visited[_x][_y] == cntr) continue;
            markIsland(_x, _y, cntr, grid, visited);
        }
    }

    void findIslandSize(int x, int y, int &cntr, vector<vector < int>> &grid, vector< vector< int>> &visited,
                       vector< vector< int>> &marker,int mrk)
    {
        int n = grid.size(), m = grid[0].size();
        visited[x][y] = true;
        marker[x][y]=mrk;
        cntr++;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= m || _x < 0 || _y < 0 || !grid[_x][_y] || visited[_x][_y]) continue;
            findIslandSize(_x, _y, cntr, grid, visited,marker,mrk);
        }
    }

    int largestIsland(vector<vector < int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector < int>> visited(n, vector<int> (m, 0));
        vector<vector < int>> marker(n, vector<int> (m, 0));
        int mrk=1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!grid[i][j] || visited[i][j]) continue;
                int cntr = 0;
                findIslandSize(i, j, cntr, grid, visited,marker,mrk);
                markIsland(i, j, cntr, grid, visited);
                mrk++;
            }
        }
        int largest=1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout<<visited[i][j]<<" ";
                map<int,int>val;
                for (int k = 0; k < 4; k++)
                {
                    int _x = i + moveX[k], _y = j + moveY[k];
                    if (_x >= n || _y >= m || _x < 0 || _y < 0 || !grid[_x][_y]) continue;
                    val[marker[_x][_y]]=visited[_x][_y];
                }
                if(val.empty())continue;
                int sum=0;
                for(auto x:val)sum+=x.second;
                largest=max(largest,sum+(grid[i][j]==0));
            }
            // cout<<"\n";
        }
        // cout<<"\n";
        return largest;
    }
};