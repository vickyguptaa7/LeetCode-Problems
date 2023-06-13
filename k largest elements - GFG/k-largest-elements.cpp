//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>,greater<int>>pque;
	    
	    for(int i=0;i<k;i++)
	        pque.push(arr[i]);
	        
	    for(int i=k;i<n;i++)
	    {
	        pque.push(arr[i]);
	        pque.pop();
	    }
	    
	    vector<int>result;
	    while(!pque.empty())
	    {
	        result.push_back(pque.top());
	        pque.pop();
	    }
	    
	    reverse(result.begin(),result.end());
	    
	    return result;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends