//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a, b, c;
        cin >> a >> b >> c;
        int n;
        cin >> n;
        vector<long long int>arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long int>ans = sortArray(arr, n, a, b, c);
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends


vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C){
    //complete the function here

    for(auto &x:arr)
    {
        x=x*x*A+B*x+C;
    }
    sort(arr.begin(),arr.end());
    return arr;
}