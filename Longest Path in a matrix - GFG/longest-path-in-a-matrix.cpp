// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int>moveX={0,0,1,-1};
    vector<int>moveY={1,-1,0,0};
    
    int dfs_helper(int x,int y,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int rows=matrix.size(),cols=matrix[0].size();
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            
            if(_x>=rows||_x<0||_y>=cols||_y<0||matrix[_x][_y]<=matrix[x][y])
                continue;
                
            dp[x][y]=max(1+dfs_helper(_x,_y,matrix,dp),dp[x][y]);
        }
        if(dp[x][y]==-1)return dp[x][y]=1;
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        int ans;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                ans=max(ans,dfs_helper(i,j,matrix,dp));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends