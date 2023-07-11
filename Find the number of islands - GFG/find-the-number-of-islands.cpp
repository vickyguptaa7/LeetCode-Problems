//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    vector<int>moveX={1,-1,0,0,1,-1,1,-1};
    vector<int>moveY={0,0,-1,1,1,1,-1,-1};
  public:
    // Function to find the number of islands.
    void dfs(int x,int y,vector<vector<char>>&grid,vector<vector<bool>>&visit)
    {
        int n=grid.size(),m=grid[0].size();
        visit[x][y]=true;
        for(int i=0;i<8;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=n||_y>=m||_x<0||_y<0||visit[_x][_y]||grid[_x][_y]=='0')continue;
            dfs(_x,_y,grid,visit);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,0));
        int island=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visit[i][j]||grid[i][j]=='0')continue;
                island++;
                dfs(i,j,grid,visit);
            }
        }
        return island;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends