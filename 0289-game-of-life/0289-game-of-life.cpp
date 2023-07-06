class Solution {
public:
    
    vector<int>moveX={0,0,1,-1,1,-1,1,-1};
    vector<int>moveY={1,-1,0,0,1,-1,-1,1};
    
    int findNeighbours(int x,int y,vector<vector<int>>&board)
    {
        int n=board.size(),m=board[0].size();
        int count=0;
        for(int i=0;i<8;i++)
        {
            int _x=moveX[i]+x,_y=moveY[i]+y;
            if(_x>=n||_y>=m||_x<0||_y<0)continue;
            if(board[_x][_y]%2==1)
                count++;
        }
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ncount=findNeighbours(i,j,board);
                if(board[i][j]&&(ncount==2||ncount==3))
                    board[i][j]+=2;
                if(!board[i][j]&&(ncount==3))
                    board[i][j]+=2;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]/=2;
            }
        }
        
    }
};