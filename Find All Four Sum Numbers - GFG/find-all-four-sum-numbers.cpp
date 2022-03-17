// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

bool mycomp(vector<int>&a,vector<int>&b)
{
    for(int i=0;i<4;i++)
    {
        if(a[i]!=b[i])
        {
            return a[i]<b[i];
        }
    }
    return a[3]<b[3];
}

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        vector<vector<int> >answer;
        set<vector<int>>oset;
        int n=arr.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int low=j+1,high=n-1;
                while(low<high)
                {
                    int sum=arr[i]+arr[j]+arr[low]+arr[high];
                    if(sum==k)
                    {
                        oset.insert({arr[i],arr[j],arr[low],arr[high]});
                        low++;
                        high--;
                    }
                    else if(sum>k)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        for(auto x:oset)
        {
            answer.push_back(x);
        }
        sort(answer.begin(),answer.end(),mycomp);
        return answer;
    }
};
/*
25 234
57 81 93 58 70 99 17 39 69 63 22 94 73 47 31 62 82 90 92 91 57 15 21 57 74
*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends