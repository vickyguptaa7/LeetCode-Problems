//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    int maxIndexDiff(int arr[], int n) {
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.empty()||arr[i]<mp.begin()->first)
            {
                mp[arr[i]]=i;
            }
            else
            {
                auto ele=mp.lower_bound(arr[i]);
                if(ele!=mp.end()&&ele->first==arr[i])
                {
                    ans=max(i-ele->second,ans);
                }
                else
                {
                    ele=prev(ele);
                    // cout<<ele->second<<" "<<ele->first<<"\n";
                    // if(ele!=mp.rend())
                    {
                        ans=max(ans,i-ele->second);
                    }
                }
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends