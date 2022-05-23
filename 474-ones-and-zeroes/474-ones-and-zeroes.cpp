class Solution {
public:
    int dp[601][101][101];
    
    int helper(int s,vector<pair<int,int>>&arr,int m,int n)
    {
        if(s==arr.size()||m<0||n<0)
        {
            return 0;
        }
        
        if(dp[s][m][n]!=-1)return dp[s][m][n];
        
        int zc=arr[s].first,oc=arr[s].second;
        
        if(m>=zc&&n>=oc)
        {
            return dp[s][m][n]=max(helper(s+1,arr,m,n),1+helper(s+1,arr,m-zc,n-oc));
        }
        else
        {
            return dp[s][m][n]=helper(s+1,arr,m,n);
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>freqArr;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            int oc=0,zc=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='1')oc++;
                else zc++;
            }
            freqArr.push_back({zc,oc});
        }
        for(int i=0;i<601;i++)
        {
            for(int j=0;j<101;j++)
            {
                for(int k=0;k<101;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return helper(0,freqArr,m,n);
    }
};