class Solution {
public:
    
    vector<int>moveX={0,0,-1,1};
    vector<int>moveY={1,-1,0,0};
    void dfs(int x,int y,vector<vector<int>>&heights,
             vector<vector<int>>&ocean)
    {   
        int rows=heights.size(),cols=heights[0].size();
        ocean[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=rows||_y>=cols)
            {
                continue;
            }
            if(_x<0||_y<0)
            {
                continue;
            }
            if(ocean[_x][_y]||heights[x][y]>heights[_x][_y])
            {
                continue;
            }
            dfs(_x,_y,heights,ocean);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
        int rows=heights.size(),cols=heights[0].size();
        
        vector<vector<int>>pacific(rows,vector<int>(cols,0)),atlantic(rows,vector<int>(cols,0));
        
        for(int i=0;i<rows;i++)
        {
            dfs(i,0,heights,pacific);
            dfs(i,cols-1,heights,atlantic);
        }
        for(int i=0;i<cols;i++)
        {
            dfs(0,i,heights,pacific);
            dfs(rows-1,i,heights,atlantic);
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(pacific[i][j]&&atlantic[i][j])result.push_back({i,j});
            }
        }
        return result;
    }
};