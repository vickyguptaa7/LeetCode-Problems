class Solution {
public:
    
    vector<int>moveX={0,0,-1,1};
    vector<int>moveY={1,-1,0,0};
    void dfs(int x,int y,vector<vector<int>>&heights,
             vector<vector<int>>&visit,bool &pacific,bool &atlantic)
    {
        if(atlantic&&pacific)
        {
            return;
        }
        
        int rows=heights.size(),cols=heights[0].size();
        visit[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=rows||_y>=cols)
            {
                atlantic=true;
                continue;
            }
            if(_x<0||_y<0)
            {
                pacific=true;
                continue;
            }
            if(visit[_x][_y]||heights[x][y]<heights[_x][_y])
            {
                continue;
            }
            dfs(_x,_y,heights,visit,pacific,atlantic);
        }
        visit[x][y]=false;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
        int rows=heights.size(),cols=heights[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,-1)),visit(rows+1,vector<int>(cols+1,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                bool pacific=false,atlantic=false;
                dfs(i,j,heights,visit,pacific,atlantic);
                if(pacific&&atlantic)
                {
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};