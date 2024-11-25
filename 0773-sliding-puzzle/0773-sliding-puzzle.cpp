class Solution {
public:
    
    string convertBoardToString(vector<vector<int>>&board)
    {
        string res;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                res+=('0'+board[i][j]);
            }
        }
        return res;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,int>dp;
        queue<string>que;
        vector<int>moveX={0,0,1,-1};
        vector<int>moveY={1,-1,0,0};
        int row=board.size();
        int col=board[0].size();
        
        que.push(convertBoardToString(board));
        dp[stoi(convertBoardToString(board))]=0;
        string target="123450";

        while(!que.empty())
        {
            string curr=que.front();
            que.pop();
            if(target==curr)
            {
                return dp[stoi(curr)];
            }
            int indx=curr.find("0");
            int x=indx/col;
            int y=indx%col;
            for(int i=0;i<4;i++)
            {
                int _x=x+moveX[i],_y=y+moveY[i];
                if(_x>=row||_y>=col||_x<0||_y<0)
                {
                    continue;
                }
                string snew=curr;
                swap(snew[indx],snew[_x*3+_y]);
                if(dp.count(stoi(snew)))
                {
                    continue;
                }
                dp[stoi(snew)]=1+dp[stoi(curr)];
                que.push(snew);
            }
        }
        return -1;
    }
};