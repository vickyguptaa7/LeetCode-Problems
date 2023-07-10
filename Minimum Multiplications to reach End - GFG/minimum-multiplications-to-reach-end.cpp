//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pque;
        pque.push({0,start});
        vector<int>dist(1e5,1e9);
        int mod=1e5;
        dist[start]=0;
        while(!pque.empty())
        {
            int step=pque.top().first;
            int curr=pque.top().second;
            pque.pop();
            if(curr==end)
            {
                return step;
            }
            for(int i=0;i<arr.size();i++)
            {
                int newCurr=(curr*arr[i])%mod;
                if(dist[newCurr]>step+1)
                {
                    dist[newCurr]=step+1;
                    pque.push({step+1,newCurr});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends