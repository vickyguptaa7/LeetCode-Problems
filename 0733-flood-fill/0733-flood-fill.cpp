class Solution {
    vector<int>moveX={0,0,-1,1};
    vector<int>moveY={1,-1,0,0};
    
    void helper(int x,int y,int curColor,int color,vector<vector<int>>&image)
    {
        int n=image.size(),m=image[0].size();
        image[x][y]=color;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=n||_y>=m||_x<0||_y<0||image[_x][_y]!=curColor)
                continue;
            helper(_x,_y,curColor,color,image);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curColor=image[sr][sc];
        if(color==curColor)
            return image;
        int n=image.size(),m=image[0].size();
        helper(sr,sc,curColor,color,image);
        return image;
    }
};