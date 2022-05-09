class Solution {
public:
    int visited[101][101][101]={0};
    bool helper(vector<vector<char>>& grid,int x,int y,int bc)
    {
        int r=grid.size(),c=grid[0].size();
        if(x>=r||y>=c||x<0||y<0||bc<0||bc>(r+c)/2||visited[x][y][bc])
            return  false;
        
        visited[x][y][bc]=true;
        
        if(grid[x][y]=='(')
            bc++;
        else 
            bc--;
        
        if(x==grid.size()-1&&y==grid[0].size()-1&&bc==0)
            return true;
        // cout<<x<<" "<<y<<" "<<lc<<" "<<rc<<"\n";

        
        if(helper(grid,x+1,y,bc))return true;
        // if(x+1<r&&y+1<c&&x+1>=0&&y+1>=0&&grid[x+1][y]==grid[x][y+1])return false;
        if(helper(grid,x,y+1,bc))return true;
        
        
        return  false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int r=grid.size(),c=grid[0].size();
        return helper(grid,0,0,0);
    }
};