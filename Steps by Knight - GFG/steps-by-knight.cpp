//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<int,int>>que;
	    que.push({KnightPos[0],KnightPos[1]});
	    
	    
	    vector<vector<bool>>visited(N+1,vector<bool>(N+1,0));
	    int curr=0;
	    
	    visited[KnightPos[0]][KnightPos[1]]=true;
	    
	    vector<int>moveX={1,2,-2,-1,1,2,-1,-2};
	    vector<int>moveY={2,1,1,2,-2,-1,-2,-1};
	    
	    while(!que.empty())
	    {
	        int size=que.size();
	        while(size--)
	        {
	           auto x=que.front().first;
	           auto y=que.front().second;
	           que.pop();
	           if(x==TargetPos[0]&&y==TargetPos[1])
	                return curr;
	           for(int i=0;i<8;i++)
	           {
	               int _x=x+moveX[i],_y=y+moveY[i];
	               if(_x>N||_y>N||_x<1||_y<0||visited[_x][_y])
	                continue;
	                visited[_x][_y]=true;
	                que.push({_x,_y});
	           }
	        }
	        curr++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends