//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int>previousSmaller(int arr[],int n)
    {
        vector<int>res;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
                st.pop();
                
            if(st.empty())
                res.push_back(-1);
            else 
                res.push_back(st.top());
                
            st.push(i);
        }
        return res;
    }
    vector<int>nextSmaller(int arr[],int n)
    {
        vector<int>res;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
                st.pop();
                
            if(st.empty())
                res.push_back(n);
            else 
                res.push_back(st.top());
                
            st.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int>prevMin=previousSmaller(arr,n);
        vector<int>nextMin=nextSmaller(arr,n);
        vector<int>res(n+1,0),ans;
        for(int i=0;i<n;i++)
        {
            int len=nextMin[i]-prevMin[i]-1;
            res[len]=max(res[len],arr[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            res[i]=max(res[i],res[i+1]);
            ans.push_back(res[i+1]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends