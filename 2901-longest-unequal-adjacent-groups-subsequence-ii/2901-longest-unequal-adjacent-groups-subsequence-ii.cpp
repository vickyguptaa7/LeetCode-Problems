class Solution {
public:
    int dp[1002][1003];
    
    int equal(string s1,string s2)
    {
        if(s1.size()!=s2.size())
            return 0; 
        
        int dif=0;
        for(int i=0;i<s1.size();i++)
            dif+=(s1[i]!=s2[i]);
        
        return dif==1;
    }
    
    int helper(int indx,int prev,vector<int>&groups,vector<string>&words,vector<int>&par)
    {
        if(indx==groups.size())
            return 0;
        
        if(dp[indx][prev+1]!=-2)
            return dp[indx][prev+1];
        
        int ans=helper(indx+1,prev,groups,words,par);
        
        if(prev==-1)
        {
            int res=1+helper(indx+1,indx,groups,words,par);
            if(ans<res)
            {
                par[0]=indx;
                ans=res;
            }
        }
        
        if(prev!=-1&&groups[prev]!=groups[indx]&&equal(words[indx],words[prev]))
        {
            int res=1+helper(indx+1,indx,groups,words,par);
            if(ans<res)
            {
                par[prev+1]=indx;
                ans=res;
            }          
        }
        
        return dp[indx][prev+1]=ans;
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        // memset(dp,-2,sizeof dp);
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1002;j++)
                dp[i][j]=-2;
        }
        vector<int>par(n+1,-1);
        cout<<helper(0,-1,groups,words,par)<<"\n";
        
        vector<string>res;
        int i=0;
        // for(int i=0;i<6;i++)
        // {
        //     for(int j=0;j<6;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // res.push_back(words[0]);
        for(auto x:par)cout<<x<<" ";
        cout<<"\n";
        int j=par[0];
        while(j<n)
        {
            res.push_back(words[j]);
            if(j>par[j+1])
                break;
            j=par[j+1];
        }
        // for(int i=1;i<=words.size();i++)
        // {
        //     if(dp[i][j+1]==dp[i-1][j]-1)
        //     {
        //         res.push_back(words[i-1]);
        //         j++;
        //     }
        //     else if(dp[i][j]==dp[i-1][j]-1)
        //     {
        //         res.push_back(words[i-1]);                
        //     }
        //     if(i==words.size()&&dp[i-1][j]==1)
        //     {
        //         res.push_back(words[i-1]);
        //     }
        // }
        return res;
    }
};