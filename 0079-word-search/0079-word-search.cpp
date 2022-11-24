class Solution {
public:
    vector<int>moveX={0,0,1,-1},moveY={1,-1,0,0};
    bool isFound(int x,int y,int s,string &word,vector<vector<char>>&board)
    {
        int n=board.size(),m=board[0].size();
        if(word.size()==s)
        {
            return true;
        }
        char prev=board[x][y];
        board[x][y]='#';
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x<0||_x>=n||_y<0||_y>=m||board[_x][_y]!=word[s])
            {
                continue;
            }
            if(isFound(_x,_y,s+1,word,board))
            {
                board[x][y]=prev;
                return true;
            }
        }
        board[x][y]=prev;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j]&&isFound(i,j,1,word,board))
                {
                    return true;
                }
            }
        }
        return false;
    }
};