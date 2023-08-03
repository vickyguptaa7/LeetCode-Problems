//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>distance(N,1e9);
        vector<pair<int,int>>list[N];
        for(auto edge:edges)
        {
            list[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pque;
        distance[0]=0;
        pque.push({0,0});
        while(!pque.empty())
        {
            int cost=pque.top().first;
            int src=pque.top().second;
            pque.pop();
            for(auto child:list[src])
            {
                if(distance[child.first]>child.second+cost)
                {
                    distance[child.first]=child.second+cost;
                    pque.push({child.second+cost,child.first});
                }
            }
        }
        for(auto& dist:distance)
        {
            dist=(dist==1e9)?-1:dist;
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends