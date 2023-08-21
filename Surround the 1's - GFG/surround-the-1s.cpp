//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    
    vector<int>moveX={0,1,-1,0,1,-1,1,-1};
    vector<int>moveY={1,0,0,-1,1,-1,-1,1};
    
public:
    int Count(vector<vector<int> >& matrix) {
        int res=0;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)continue;
                int cntr=0;
                for(int k=0;k<8;k++)
                {
                    int _x=moveX[k]+i,_y=j+moveY[k];
                    if(_x>=n||_y>=m||_x<0||_y<0)
                        continue;
                    cntr+=(matrix[_x][_y]==0);
                }
                if(cntr>0&&cntr%2==0)
                {
                    res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends