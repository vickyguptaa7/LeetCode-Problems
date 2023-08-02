//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>>visited(N,vector<int>(M,0));
        queue<pair<int,int>>que;
        que.push({0,0});
        vector<int>moveX={0,0,-1,1};
        vector<int>moveY={1,-1,0,0};
        visited[0][0]=1;
        int cntr=0;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                if(x==X&&y==Y)
                    return cntr;
                for(int i=0;i<4;i++)
                {
                    int _x=x+moveX[i],_y=y+moveY[i];
                    if(_x>=N||_x<0||_y>=M||_y<0||!A[_x][_y]||visited[_x][_y])
                        continue;
                    visited[_x][_y]=true;
                    que.push({_x,_y});
                }
            }
            cntr++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends