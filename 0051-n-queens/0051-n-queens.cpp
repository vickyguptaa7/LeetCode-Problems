class Solution {
    vector<vector<string>>ways;
    vector<string>board;
public:
    
    bool isSafePlace(int x,int y)
    {
        // checked vertically
        for(int i=0;i<x;i++)
        {
            if(board[i][y]=='Q')
                return false;
        }
        
        // check diagonaly
        int r=x,c=y;
        // diagonal 1
        while(r>=0&&c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        r=x,c=y;
        //diagonal 2
        while(r>=0&&c<board.size())
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c++;
        }
        
        return true;
    }
    
    void helper(int x)
    {
        if(x==board.size())
        {
            ways.push_back(board);
            return;
        }
        
        for(int i=0;i<board.size();i++)
        {
            if(isSafePlace(x,i))
            {
                board[x][i]='Q';
                helper(x+1);
                board[x][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++)
        {
            string c;
            for(int j=0;j<n;j++)
                c+='.';
            board.push_back(c);
        }
        helper(0);
        return ways;
    }
};