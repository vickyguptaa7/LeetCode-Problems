//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()>=2)
        {
            if(arr[0]==1&&arr[1]!=1)
                return (int)arr.size()-1;
            if(arr[0]==1&&arr[1]==1)
                return arr.size();
        }
        int cntr=0;
        for(long long i=0;i<arr.size();i++)
        {
            bool isFound=false;
            for(long long j=2;j*j<=arr[i];j++)
            {
                if(arr[i]%j==0)
                {
                    auto itr=lower_bound(arr.begin(),arr.end(),j)-arr.begin();
                    if(itr!=arr.size()&&arr[itr]==j)
                    {
                        isFound=true;
                        break;
                    }
                    itr=lower_bound(arr.begin(),arr.end(),arr[i]/j)-arr.begin();
                    if(itr!=arr.size()&&arr[itr]==(arr[i]/j))
                    {
                        isFound=true;
                        break;
                    }
                }
            }
            if(!isFound)
            {
                auto itr=lower_bound(arr.begin(),arr.end(),arr[i])-arr.begin();
                if(itr+1<arr.size()&&arr[itr+1]==arr[i])
                {
                    isFound=true;
                }
            }
            cntr+=isFound;
        }
        return cntr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends