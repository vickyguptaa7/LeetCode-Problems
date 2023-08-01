class Solution {
public:
    
    void modifyBoard(vector<vector<int>>&board)
    {
        reverse(board.begin(),board.end());
        for(int i=1;i<board.size();i+=2)
            reverse(board[i].begin(),board[i].end());
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        modifyBoard(board);
        queue<int>que;
        int n=board.size();
        int move=0;
        vector<int>visited(n*n+1,0);
        visited[1]=true;
        que.push(1);
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int curr=que.front();
                que.pop();
                if(curr==n*n)
                {
                    return move;
                }
                for(int i=1;i<=6;i++)
                {
                    int newCurr=min(curr+i,n*n);
                    int row=(newCurr-1)/n,col=(newCurr-1)%n;
                    if(visited[newCurr])continue;
                    visited[newCurr]=1;
                    if(board[row][col]==-1)
                        que.push(newCurr);
                    else 
                        que.push(board[row][col]);
                }
            }
            move++;
        }
        return -1;
    }
};