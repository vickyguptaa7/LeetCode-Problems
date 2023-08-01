//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>distance(n,1e9);
	    distance[0]=0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=0;j<edges.size();j++)
	        {
	            if(distance[edges[j][1]]>distance[edges[j][0]]+edges[j][2])
	                distance[edges[j][1]]=distance[edges[j][0]]+edges[j][2];
	        }
	    }
	   for(int j=0;j<edges.size();j++)
	   {
	       if(distance[edges[j][1]]>distance[edges[j][0]]+edges[j][2])
	            return true;
	   }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends