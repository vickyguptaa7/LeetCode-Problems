// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[0]!=b[0])
    {
        return a[0]<b[0];
    }
    if(a[1]!=b[1])
    {
        return a[1]>b[1];
    }
    return a[2]<b[2];
}

class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<vector<int>>res;
        for(int i=0;i<N;i++)
        {
            res.push_back({phy[i],chem[i],math[i]});
        }
        sort(res.begin(),res.end(),mycomp);
        for(int i=0;i<N;i++)
        {
            phy[i]=res[i][0];
            chem[i]=res[i][1];
            math[i]=res[i][2];
            
        }
    } 
};

// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends