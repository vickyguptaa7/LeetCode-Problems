class Solution {
public:

    bool isValid(int x,int y,int n,vector<vector<bool>>&board)
    {
        for(int i=0;i<=x;i++)
        {
            if(board[i][y]==true)return false;
        }
        
        int r=x,c=y;
        while(r>=0&&c>=0)
        {
            if(board[r][c]==true)return false;
            r--;
            c--;
        }
        r=x,c=y;
        while(r>=0&&c<n)
        {
            if(board[r][c]==true)return false;
            r--;
            c++;
        }
        return true;
    }
    
    void helper(int x,int n,vector<vector<bool>>board,int &ans)
    {
        if(x==n)
        {
            ans++;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isValid(x,i,n,board))
            {
                board[x][i]=true;
                helper(x+1,n,board,ans);
                board[x][i]=false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>>board(n,vector<bool>(n,0));
        int ans=0;
        helper(0,n,board,ans);
        return ans;
    }
};