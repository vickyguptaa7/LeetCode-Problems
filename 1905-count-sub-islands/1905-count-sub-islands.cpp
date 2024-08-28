class Solution {
public:
    
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};

    
    int helper(int x,int y,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&visit)
    {
        int n=grid1.size(),m=grid1[0].size();
        if(!grid1[x][y])
            return false;
        
        visit[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int _x=x+dx[i],_y=y+dy[i];
            if(_x<0||_y<0||_x>=n||_y>=m||!grid2[_x][_y]||visit[_x][_y])continue;
            if(!helper(_x,_y,grid1,grid2,visit))
            {
                visit[x][y]=false;
                return false;
            }
        }
        return true;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visit[i][j]||!grid2[i][j]||!grid1[i][j])continue;
                if(helper(i,j,grid1,grid2,visit))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};