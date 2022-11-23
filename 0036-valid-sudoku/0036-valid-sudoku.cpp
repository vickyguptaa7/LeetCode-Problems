class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            int n = 9;
            map<int, int> row[n], col[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] >= '0' && board[i][j] <= '9')
                    {
                        row[i][board[i][j]]++;
                        if (row[i][board[i][j]] > 1)
                            return false;
                    }
                    if (board[j][i] >= '0' && board[j][i] <= '9')
                    {
                        col[i][board[j][i]]++;
                        if (col[i][board[j][i]] > 1)
                            return false;
                    }
                }
            }
            for (int i = 0; i < n; i += 3)
            {
                for (int j = 0; j < n; j += 3)
                {
                    set<char> oset;
                    for (int p = i; p < i + 3; p++)
                    {
                        for (int q = j; q < j + 3; q++)
                        {
                            if (board[p][q] >= '0' && board[p][q] <= '9')
                            {
                                if (oset.count(board[p][q]))
                                    return false;
                                oset.insert(board[p][q]);
                            }
                        }
                    }
                }
            }
            return true;
        }
};