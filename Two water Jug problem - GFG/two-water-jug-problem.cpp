//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    queue<pair<int,int>>que;
	    que.push({0,0});
	    int steps=0;
	    vector<vector<int>>visited(m+1,vector<int>(n+1,0));
	    visited[m][n]=0;
	    while(!que.empty())
	    {
	        int size=que.size();
	        while(size--)
	        {
	            int cm=que.front().first;
	            int cn=que.front().second;
	            que.pop();
	            
	            if(cn==d||cm==d)
	                return steps;
	            
	            // if empty fill the jug
	            if(cm==0&&!visited[m][cn])
	            {
	                visited[m][cn]=1;
	                que.push({m,cn});
	            }
	            if(cn==0&&!visited[cm][n])
	            {
	                visited[cm][n]=1;
	                que.push({cm,n});
	            }
	            
	            // if jug are filled empty them
	            if(cm!=0&&!visited[0][cn])
	            {
	                visited[0][cn]=1;
	                que.push({0,cn});
	            }
	            if(cn!=0&&!visited[cm][0])
	            {
	                visited[cm][0]=1;
	                que.push({cm,0});
	            }
	            
	            // pour water from one jug to another
	            // m -> n
	            int newm=0,newn=0;
	            if(cm+cn>=n)
	            {
	                newn=n;
	                newm=(cm+cn)-n;
	            }
	            else
	            {
	                newn=cm+cn;
	                newm=0;
	            }
	            if(cm!=0&&!visited[newm][newn])
	            {
	                visited[newm][newn]=1;
	                que.push({newm,newn});
	            }
	            
	            // n->m
	            if(cm+cn>=m)
	            {
	                newm=m;
	                newn=(cm+cn)-m;
	            }
	            else
	            {
	                newm=cm+cn;
	                newn=0;
	            }
	            if(cn!=0&&!visited[newm][newn])
	            {
	                visited[newm][newn]=1;
	                que.push({newm,newn});
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends