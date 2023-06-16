//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    long long helper(int strt,int isFirstMin,vector<pair<int,int>>&carr,vector<vector<long long>>&dp)
    {
        long long location=0;
        long long cost1=0,cost2=0;;
        if(isFirstMin)
        {
            if(strt!=0)location=carr[strt-1].first;
        }
        else
        {
            if(strt!=0)location=carr[strt-1].second;
        }
        if(strt==carr.size())
        {
            return abs(location);
        }
        if(dp[strt][isFirstMin]!=-1)
            return dp[strt][isFirstMin];
        cost2=abs(carr[strt].first-carr[strt].second)+abs(carr[strt].first-location);
        cost1=abs(carr[strt].first-carr[strt].second)+abs(carr[strt].second-location);
        return dp[strt][isFirstMin]=min(cost2+helper(strt+1,0,carr,dp),cost1+helper(strt+1,1,carr,dp));
    }
    
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        map<int,pair<int,int>>combine;
        for(int i=0;i<n;i++)
        {
            if(combine.count(types[i]))
                combine[types[i]]={min(locations[i],combine[types[i]].first),max(locations[i],combine[types[i]].second)};
            else 
                combine[types[i]]={locations[i],locations[i]};
        }
        vector<pair<int,int>>carr;
        for(auto x:combine)
        {
            carr.push_back(x.second);
        }
        vector<vector<long long>>dp(combine.size(),vector<long long>(2,-1));
        return min(helper(0,0,carr,dp),helper(0,1,carr,dp));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends