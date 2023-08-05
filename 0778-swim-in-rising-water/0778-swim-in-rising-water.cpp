class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>time(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pque;
        
        time[0][0]=grid[0][0];
        pque.push({grid[0][0],{0,0}});
        vector<int>moveX={0,0,-1,1},moveY={1,-1,0,0};
        while(!pque.empty())
        {
            int cost=pque.top().first;
            int x=pque.top().second.first;
            int y=pque.top().second.second;
            pque.pop();
            if(x==n-1&&y==m-1)
                return cost;
            for(int i=0;i<4;i++)
            {
                int _x=x+moveX[i],_y=y+moveY[i];
                if(_x>=n||_y>=m||_x<0||_y<0)
                    continue;
                if(time[_x][_y]>max(cost,grid[_x][_y]))
                {
                    time[_x][_y]=max(cost,grid[_x][_y]);
                    pque.push({time[_x][_y],{_x,_y}});
                }
            }
        }
        return -1;
    }
};