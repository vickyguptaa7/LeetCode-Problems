typedef pair<int,pair<int,int>> ppi;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        if(grid[0][1]>1&&grid[1][0]>1)
            return -1;
        
        vector<vector<int>>visit(n,vector<int>(m,0));
        
        vector<int>moveX={0,0,-1,1};
        vector<int>moveY={-1,1,0,0};
        
        priority_queue<ppi,vector<ppi>,greater<ppi>>pque;
        pque.push({0,{0,0}});
        visit[0][0]=1;
        
        while(!pque.empty())
        {
            int ctime=pque.top().first;
            int x=pque.top().second.first;
            int y=pque.top().second.second;
            pque.pop();
            
            if(x==n-1&&y==m-1)
                return ctime;
            
            for(int i=0;i<moveX.size();i++)
            {
                int _x=x+moveX[i],_y=y+moveY[i];
                if(_x>=n||_y>=m||_x<0||_y<0||visit[_x][_y])
                {
                    continue;
                }
                visit[_x][_y]=true;
                
                if(ctime+1>=grid[_x][_y])
                {
                    pque.push({ctime+1,{_x,_y}});                    
                }
                else
                {
                    int rem=grid[_x][_y]-(ctime+1);
                    if(rem&1)
                    {
                        pque.push({grid[_x][_y]+1,{_x,_y}});
                    }
                    else
                    {
                        pque.push({grid[_x][_y],{_x,_y}});
                    }
                }
            }
        }
        return -1;
    }
};