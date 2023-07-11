//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    
    vector<int>nextSmallestLeft(vector<int>&arr)
    {
        vector<int>left;
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
                left.push_back(-1);
            else 
                left.push_back(st.top());
            st.push(i);
        }
        return left;
    }
    
    vector<int>nextSmallestRight(vector<int>&arr)
    {
        vector<int>right;
        stack<int>st;
        for(int i=(int)arr.size()-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
                right.push_back(arr.size());
            else 
                right.push_back(st.top());
            st.push(i);
        }
        reverse(right.begin(),right.end());
        return right;
    }
    
    
    int maxAreaHistogram(vector<int>&arr)
    {
        vector<int>leftSmall=nextSmallestLeft(arr);
        vector<int>rightSmall=nextSmallestRight(arr);
        int area=0;
        for(int i=0;i<arr.size();i++)
        {
            area=max(area,(rightSmall[i]-leftSmall[i]-1)*arr[i]);
        }
        return area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int mxArea=0;
        vector<int>arr(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!M[i][j])
                {
                   arr[j]=M[i][j]; 
                }
                else 
                    arr[j]+=M[i][j];
            }
            mxArea=max(mxArea,maxAreaHistogram(arr));
        }
        return mxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends