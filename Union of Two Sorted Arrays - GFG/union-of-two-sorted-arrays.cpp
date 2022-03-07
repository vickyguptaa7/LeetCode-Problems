// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int>res;
        int it1=0,it2=0;
        while(it1<n&&it2<m)
        {
            if(arr1[it1]==arr2[it2]){
                it1++;
                continue;
            };
            if(arr1[it1]>arr2[it2])
            {
                res.push_back(arr2[it2]);
                it2++;
                while(it2<m&&arr2[it2-1]==arr2[it2])it2++;
            }
            else
            {
                res.push_back(arr1[it1]);
                it1++;
                while(it1<n&&arr1[it1-1]==arr1[it1])it1++;
            }
        }
        while(it1<n)
        {
            res.push_back(arr1[it1]);
            it1++;
            while(it1<n&&arr1[it1-1]==arr1[it1])it1++;
        }
        while(it2<m)
        {
            res.push_back(arr2[it2]);
            it2++;
            while(it2<m&&arr2[it2-1]==arr2[it2])it2++;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends