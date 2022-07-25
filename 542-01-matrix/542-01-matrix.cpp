class Solution {
public:
    vector<int>moveX={1,-1,0,0};
    vector<int>moveY={0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>result(n,vector<int>(m,1e9));
        queue<pair<int,int>>que;
        int time=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    result[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty())
        {
            time++;
            int size=que.size();
            while(size--)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int _x=x+moveX[i],_y=y+moveY[i];
                    if(_x>=n||_y>=m||_x<0||_y<0||mat[_x][_y]==0)continue;
                    if(result[_x][_y]<time)continue;
                    result[_x][_y]=time;
                    que.push({_x,_y});
                }
            }
        }
        return result;
    }
};