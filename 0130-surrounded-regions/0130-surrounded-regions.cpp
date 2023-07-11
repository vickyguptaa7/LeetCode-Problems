class Solution
{
    public:
        vector<int>moveX={0,0,-1,1};
        vector<int>moveY={-1,1,0,0};

        void isSurroundedByX(int x, int y, vector<vector < char>> &board,
            vector<vector < int>> &visit,bool &isTouchedEnd)
        {
            int n = board.size(), m = board[0].size();
            visit[x][y] = true;
            for (int i = 0; i < 4; i++)
            {
                int _x = x + moveX[i], _y = y + moveY[i];
                if (_x >= n || _y >= m || _x < 0 || _y < 0)
                {
                    isTouchedEnd=true;
                    continue;
                }
                if (board[_x][_y] == 'X' || visit[_x][_y]) continue;
                isSurroundedByX(_x, _y, board, visit,isTouchedEnd);
            }
        }

    void markWithX(int x, int y, vector<vector < char>> &board)
    {
        int n = board.size(), m = board[0].size();
        board[x][y]='X';
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= m || _x < 0 || _y < 0||
                board[_x][_y] == 'X')
                continue;
            markWithX(_x, _y, board);
        }
    }
    void solve(vector<vector < char>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector < int>> visit(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                
                if (board[i][j] == 'O' && visit[i][j]==0 )
                {
                    bool isTouchedEnd=false;
                    isSurroundedByX(i, j, board, visit,isTouchedEnd);
                    if(!isTouchedEnd)
                        markWithX(i, j, board);
                }
            }
        }
    }
};