class Solution {
public:
    pair<int,int> Coordinates(int num,int n)
    {
        pair<int,int>cor;
        int rows=(num-1)/n,col=(num-1)%n;
        if(rows%2==0)
        {
            cor.second=col;
        }
        else
        {
            cor.second=n-1-col;
        }
        cor.first=n-1-rows;
        return cor;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int bsize=board.size();
        
        vector<vector<int>>isVisited(board.size(),vector<int>(board.size(),0));
        
        queue<int>que;
       
        que.push(1);
        
        isVisited[bsize-1][0]=1;
        
        int move=0;
        
        while(que.size())
        {
            int size=que.size();
            while(size--)
            {
                int node=que.front();
                que.pop();
                if(node==bsize*bsize)return move;
                
                for(int i=1;i<=6;i++)
                {
                    pair<int,int>cr=Coordinates(node+i,bsize);
                    
                    if(node+i>bsize*bsize)break;
                   
                    if(isVisited[cr.first][cr.second]==0)
                    {
                        isVisited[cr.first][cr.second]=1;
                        if(board[cr.first][cr.second]==-1)
                        {
                            que.push(node+i);
                        }
                        else 
                        {
                                que.push
                                    (board[cr.first][cr.second]);
                        }
                    }
                }
            }
            move++;
        }
        
            
        
        return -1;
    }
};