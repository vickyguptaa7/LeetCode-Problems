class Solution {
public:
    
    vector<int>moveX={1,-1,0,0};
    vector<int>moveY={0,0,-1,1};
    
    int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visit)
    {
        if(grid[i][j])
            return false;
        int row=grid.size(),col=grid[0].size();
        queue<pair<int,int>>que;
        visit[i][j]=true;
        que.push({i,j});
        while(!que.empty())
        {
            auto [x,y]=que.front();
            if(x+1==row)
                return true;
            que.pop();
            for(int i=0;i<4;i++)
            {
                int _x=x+moveX[i],_y=y+moveY[i];
                if(_x>=row||_y>=col||_x<0||_y<0||visit[_x][_y]||grid[_x][_y])continue;
                que.push({_x,_y});
                visit[_x][_y]=true;
            }
        }
        return false;
    }
    
    int isValid(int mid,vector<vector<int>>&cells,vector<vector<int>>&grid,vector<vector<int>>&visit)
    {
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                grid[i][j]=0;
                visit[i][j]=0;
            }
        }
        for(int i=0;i<mid;i++)
        {
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        for(int i=0;i<col;i++)
        {
            if(helper(0,i,grid,visit))
            {
                return true;
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=1,high=row*col,result=2;
        vector<vector<int>>grid(row,vector<int>(col,0));
        vector<vector<int>>visit(row,vector<int>(col,0));
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(mid,cells,grid,visit))
            {
                low=mid+1;
                result=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        return result;
    }
};