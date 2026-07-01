class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,-1,1};

    int helper(int x,int y,vector<vector<int>>&grid)
    {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>>pque;
        vector<vector<int>>visited(n,vector<int>(n,0));
        pque.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        while(pque.size())
        {
            int cost = pque.top().first;
            int x = pque.top().second.first;
            int y = pque.top().second.second;
            if(x==n-1&&y==n-1)
                return cost;
            pque.pop();
            for(int i=0;i<4;i++)
            {
                int _x=x+dx[i],_y=y+dy[i];
                if(_x<0||_y<0||_x>=n||_y>=n||visited[_x][_y])
                    continue;
                pque.push({min(cost,grid[_x][_y]),{_x,_y}});
                visited[_x][_y]=1;
            }

        }
        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ngrid(n,vector<int>(n,0));
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    que.push({i,j});
                    ngrid[i][j]=1;
                }
            }
        }
        while(que.size())
        {
            int size=que.size();
            while(size--)
            {
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            for(int i=0;i<4;i++)
            {
                int _x=x+dx[i],_y=y+dy[i];
                if(_x<0||_y<0||_x>=n||_y>=n||ngrid[_x][_y])
                    continue;
                ngrid[_x][_y]=ngrid[x][y]+1;
                que.push({_x,_y});
            }
            }
        }
        for(auto x:ngrid)
        {
            for(auto y:x)
            {
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        return helper(0,0,ngrid)-1;
    }
};