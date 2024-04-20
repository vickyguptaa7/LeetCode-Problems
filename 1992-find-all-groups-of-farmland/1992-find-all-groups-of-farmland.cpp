class Solution {
    vector<int>dx={0,0,-1,1};
    vector<int>dy={1,-1,0,0};
public:
    
    bool check(int x,int y,vector<vector<int>>&land,vector<vector<int>>&visit)
    {
        int n=land.size(),m=land[0].size();
        if(x>=n||y>=m||x<0||y<0||visit[x][y]||land[x][y]==0)return false;
        return true;
    }
    
    void dfs(int x,int y,vector<int>&curr,vector<vector<int>>&land,vector<vector<int>>&visit)
    {
        visit[x][y]=true;
        for(int i=0;i<dx.size();i++)
        {
            int _x=x+dx[i],_y=y+dy[i];
            if(check(_x,_y,land,visit))
            {
                if(curr[2]<=_x)
                    curr={curr[0],curr[1],_x,max(curr[3],_y)};
                dfs(_x,_y,curr,land,visit);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>>res,visit(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visit[i][j]||land[i][j]==0)continue;
                vector<int>curr={i,j,i,j};
                dfs(i,j,curr,land,visit);
                res.push_back(curr);
            }
        }
        return res;
    }
};