//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>result(n,vector<int>(m,1e9));
	    queue<pair<int,int>>que;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(!grid[i][j])continue;
	            que.push({i,j});
	            result[i][j]=0;
	        }
	    }
	    int level=0;
	    vector<int>moveX={0,0,1,-1},moveY={1,-1,0,0};
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
	                if(_x>=n||_y>=m||_x<0||_y<0)continue;
	                if(result[_x][_y]>level+1)
	                {
	                    result[_x][_y]=level+1;
	                    que.push({_x,_y});
	                }
	            }
	        }
	        level++;
	    }
	    return result;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends