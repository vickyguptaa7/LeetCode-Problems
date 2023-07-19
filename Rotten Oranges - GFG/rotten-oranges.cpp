//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>que;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    que.push({i,j});
                    visited[i][j]=0;
                }
            }
        }
        int time=0;
        vector<int> moveX = {0, 0, 1, -1}, moveY = {1, -1, 0, 0};
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int _x=x+moveX[i],_y=y+moveY[i];
                    if(_x>=n||_y>=m||_x<0||_y<0||grid[_x][_y]==0)
                        continue;
                    if(visited[_x][_y]>time+1)
                    {
                        visited[_x][_y]=time+1;
                        que.push({_x,_y});
                    }
                }
            }
            time++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&visited[i][j]==1e9)
                    return -1;
            }
        }
        return time-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends