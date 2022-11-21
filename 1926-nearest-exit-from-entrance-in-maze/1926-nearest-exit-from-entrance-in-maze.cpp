class Solution {
public:
    vector<int>moveX={1,-1,0,0};
    vector<int>moveY={0,0,1,-1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>que;
        que.push({entrance[0],entrance[1]});
        int step=0,n=maze.size(),m=maze[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        visited[entrance[0]][entrance[1]]=1;
        while(!que.empty())
        {
            int size=que.size();
            step++;
            while(size--)
            {
                auto [x,y]=que.front();
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int _x=x+moveX[i],_y=moveY[i]+y;
                    if(_x>=n||_x<0||_y>=m||_y<0||maze[_x][_y]=='+'||visited[_x][_y])
                        continue;
                    if(_x==n-1||_y==m-1||_x==0||_y==0)
                    {
                        return step;
                    }
                    visited[_x][_y]=1;
                    que.push({_x,_y});
                }
            }
        }
        return -1;
    }
};