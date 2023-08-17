class Solution
{
    public:

        bool isValidMove(int x, int y, int num, vector<vector < char>> &board)
        {
            int row = (x / 3)*3, col = (y / 3)*3;

           	// 3 * 3 size matrix checking
            for (int i = row; i < row + 3; i++)
            {
                for (int j = col; j < col + 3; j++)
                {
                    if (board[i][j] == num + '0')
                        return false;
                }
            }

           	// top checking
            for (int i = 0; i < 9; i++)
            {
                if (board[i][y] == num + '0')
                    return false;
            }

           	// left checking
            for (int i = 0; i < 9; i++)
            {
                if (board[x][i] == num + '0')
                    return false;
            }

            return true;
        }

    bool helper(int x, int y, vector<vector < char>> &board)
    {
        int n = board.size(), m = board[0].size();
        if (x == n)
        {
            return true;
        }
        
        if(y==m)
        {
            return helper(x+1,0,board);
        }
        
        if (board[x][y] != '.') 
        {
            return helper(x,y+1,board);
        }
        
        for (int j = 1; j <= 9; j++)
            if (isValidMove(x, y, j, board))
            {
                board[x][y] = j + '0';
                if (helper(x ,y+1, board))
                    return true;
                board[x][y] = '.';
            }

        return false;
    }

    void solveSudoku(vector<vector < char>> &board)
    {
        helper(0, 0, board);
    }
};