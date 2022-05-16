class Solution {
public:

    vector<int>moveX={0,1,0,1,-1,-1,1,-1};
    vector<int>moveY={1,0,-1,1,-1,0,-1,1};
    
    bool isValidMove(int x,int y,int rows,int cols,vector<vector<bool>>&isVisited)
    {
        if(x>=rows||y>=cols||x<0||y<0||isVisited[x][y]==true)return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1)return -1;
        
        int rows=grid.size(),cols=grid[0].size();
        
        vector<vector<bool>>isVisited(rows,vector<bool>(cols,false));
        
        queue<pair<int,int>>que;
        que.push({0,0});
        isVisited[0][0]=true;
        int shortPath=0;

        while(!que.empty())
        {
            shortPath++;
            int size=que.size();
            while(size--)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                
                if(x==rows-1&&y==cols-1)
                    return shortPath;
                
                for(int i=0;i<8;i++)
                {
                    int _x=x+moveX[i],_y=y+moveY[i];
                    if(isValidMove(_x,_y,rows,cols,isVisited)&&grid[_x][_y]==0)
                    {
                        // cout<<_x<<" "<<_y<<"\n";
                        isVisited[_x][_y]=true;
                        que.push({_x,_y});
                    }
                }
            }
        }
        return -1;
    }
};

// typedef pair<int,pair<int,int>> pip;
// class Solution {
// public:

//     vector<int>moveX={0,1,0,1,-1,-1,1,-1};
//     vector<int>moveY={1,0,-1,1,-1,0,-1,1};
    
//     bool isValidMove(int x,int y,int rows,int cols,vector<vector<bool>>&isVisited)
//     {
//         if(x>=rows||y>=cols||x<0||y<0||isVisited[x][y]==true)return false;
//         return true;
//     }
    
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
//         if(grid[0][0]==1)return -1;
        
//         int rows=grid.size(),cols=grid[0].size();
        
//         vector<vector<bool>>isVisited(rows,vector<bool>(cols,false));
        
//         priority_queue<pip,vector<pip>,greater<pip>>pque;
//         pque.push({1,{0,0}});

//         while(!pque.empty())
//         {
//             int cost=pque.top().first;
//             int x=pque.top().second.first;
//             int y=pque.top().second.second;
//             pque.pop();
                
//             if(x==rows-1&&y==cols-1)
//                 return cost;
                
//             isVisited[x][y]=true;
                
//             for(int i=0;i<8;i++)
//             {
//                 int _x=x+moveX[i],_y=y+moveY[i];
//                 if(isValidMove(_x,_y,rows,cols,isVisited)&&grid[_x][_y]==0)
//                 {
//                     // cout<<_x<<" "<<_y<<"\n";
//                     pque.push({cost+1,{_x,_y}});
//                 }
//             }
//         }
//         return -1;
//     }
// };