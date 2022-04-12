class Solution {
public:
    int adjacentLive(vector<vector<int>>& board,int i,int j)
    {
        int arr_x[]={1,-1,1,-1,0,1,0,-1};
        int arr_y[]={-1,1,1,-1,1,0,-1,0};
        int counter=0;
        for(int k=0;k<8;k++)
        {
            int _x=arr_x[k]+i,_y=arr_y[k]+j;
            if(_x<0||_y<0||_x>=board.size()||_y>=board[0].size()||board[_x][_y]%2==0)continue;
            counter++;
        }
        return counter;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                board[i][j]+=2*adjacentLive(board,i,j);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int liveCells=board[i][j]/2;
                bool isLive=board[i][j]%2;
                if(isLive)
                {
                    if(liveCells==2||liveCells==3)
                        board[i][j]=1;
                    else 
                        board[i][j]=0;
                }
                else 
                {
                    if(liveCells==3)
                        board[i][j]=1;
                    else 
                        board[i][j]=0;
                }
            }
        }
        return;
    }
};