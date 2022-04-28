typedef pair<int,pair<int,int>> ppi;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int>move_X={0,1,0,-1};
        vector<int>move_Y={-1,0,1,0};
        
        int row=heights.size(),col=heights[0].size();
        
        vector<vector<int>>dp(row,vector<int>(col,1e9));
        
        priority_queue<ppi,vector<ppi>,greater<ppi>>pque;
        pque.push({0,{0,0}});
        while(!pque.empty())
        {
            int x=pque.top().second.first;
            int y=pque.top().second.second;
            int absDiff=pque.top().first;
            pque.pop();
            // cout<<x<<" "<<y<<"\n";
            if(x==row-1&&y==col-1)
            {
                return absDiff;
            }
            
            for(int i=0;i<4;i++)
            {
                int _x=x+move_X[i];
                int _y=y+move_Y[i];
                if(_x>=row||_x<0||_y>=col||_y<0)
                    continue;
                
                int diff=max(absDiff,abs(heights[x][y]-heights[_x][_y]));
                if(dp[_x][_y]>diff)
                {
                    dp[_x][_y]=diff;
                    pque.push({diff,{_x,_y}});
                }
            }
        }
        return 0;
    }
};