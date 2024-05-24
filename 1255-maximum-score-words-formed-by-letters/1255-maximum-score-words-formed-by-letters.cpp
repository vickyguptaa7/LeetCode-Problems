class Solution {
public:
    
    int helper(int indx,vector<string>&words,vector<int>&freq,vector<int>&score,map<vector<int>,int>dp[])
    {
        if(indx==words.size())
            return 0;
        if(dp[indx].count(freq))
        {
            return dp[indx][freq];
        }
        int ans=helper(indx+1,words,freq,score,dp);
        bool isNeg=false;
        int profit=0;
        for(int i=0;i<words[indx].size();i++)
        {
            freq[words[indx][i]-'a']--;
            profit+=score[words[indx][i]-'a'];
            if(freq[words[indx][i]-'a']<0)isNeg=true;
        }
        if(!isNeg)
            ans=max(ans,profit+helper(indx+1,words,freq,score,dp));
        for(int i=0;i<words[indx].size();i++)
        {
            freq[words[indx][i]-'a']++;
        }
        return dp[indx][freq]=ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        map<vector<int>,int>dp[n];
        vector<int>freq(26,0);
        for(auto ch:letters)
            freq[ch-'a']++;
        return helper(0,words,freq,score,dp);
    }
};