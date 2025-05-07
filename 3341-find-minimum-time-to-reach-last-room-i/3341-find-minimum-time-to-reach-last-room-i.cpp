class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pque;
        pque.push({0,{0,0}});
        vector<vector<int>>visited(51,vector<int>(51,0));
        vector<int>moveX={1,0,0,-1};
        vector<int>moveY={0,-1,1,0};
        
        visited[0][0]=true;
        while(pque.size())
        {
            int cost=pque.top().first;
            int x=pque.top().second.first;
            int y=pque.top().second.second;
            pque.pop();
            if(x==n-1&&y==m-1)
            {
                return cost;
            }
            for(int i=0;i<4;i++)
            {
                int _x=moveX[i]+x,_y=moveY[i]+y;
                if(_x>=n||_x<0||_y<0||_y>=m||visited[_x][_y])
                {
                    continue;
                }
                int newCost=cost>=moveTime[_x][_y]?cost+1:moveTime[_x][_y]+1;
                pque.push({newCost,{_x,_y}});
            }
        }
        return -1;
    }
};