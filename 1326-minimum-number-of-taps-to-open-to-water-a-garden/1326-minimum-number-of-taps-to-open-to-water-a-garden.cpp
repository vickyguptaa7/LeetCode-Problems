class Solution {
public:
    
    int helper(int indx,vector<pair<int,int>>&range,vector<int>&dp,int n)
    {
        if(indx==range.size())
        {
            return 0;
        }
        
        if(dp[indx]!=-1)
            return dp[indx];
        
        int mnTap=1e9;
        if(range[indx].second>=n)
                return 1;
        for(int i=indx+1;i<range.size();i++)
        {
            if(range[indx].second>=range[i].first)
            {
                mnTap=min(mnTap,1+helper(i,range,dp,n));
            }
            else 
            {
                    break;
            }
        }
        
        return dp[indx]=mnTap;
    }
    
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>nrange;
        for(int i=0;i<ranges.size();i++)
        {
            nrange.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        sort(nrange.begin(),nrange.end());
        vector<int>dp(n+1,-1);
        
        for(auto x:nrange)
            cout<<x.first<<" "<<x.second<<'\n';     
        int mnTap=1e9;
        for(int i=0;i<nrange.size();i++)
        {
            if(nrange[i].first==0)
                mnTap=min(mnTap,helper(i,nrange,dp,n));
            else 
                break;
        }
            
        return mnTap==1e9?-1:mnTap;
    }
};