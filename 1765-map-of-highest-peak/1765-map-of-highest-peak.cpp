class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>>output(n,vector<int>(m,-1));
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j])
                {
                    output[i][j]=-2;
                    que.push({i,j});
                }
            }
        }
        vector<int>moveX={0,0,1,-1};
        vector<int>moveY={1,-1,0,0};
        int lvl=0;
        while(!que.empty())
        {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                int x=que.front().first;
                int y=que.front().second;
                output[x][y]=lvl;
                que.pop();
                for(int j=0;j<moveX.size();j++)
                {
                    int _x=x+moveX[j],_y=y+moveY[j];
                    if(_x<0||_y<0||_x>=n||_y>=m||output[_x][_y]!=-1)
                    {
                        continue;
                    }
                    output[_x][_y]=-2;
                    que.push({_x,_y});
                }
            }
            lvl++;
        }
        return output;
    }
};