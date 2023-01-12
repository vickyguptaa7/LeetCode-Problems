class Solution {
public:
    
    void combineFreq(vector<int>&freq1,vector<int>freq2)
    {
        for(int i=0;i<26;i++)
        {
            freq1[i]+=freq2[i];
        }
    }
    
    vector<int>helper(int src,int par,vector<int>list[],string &labels,
                     vector<int>&result)
    {
        vector<int>freq(26,0);
        for(auto curr : list[src])
        {
            if(curr!=par)
            {
                combineFreq(freq,helper(curr,src,list,labels,result));
            }
        }
        freq[labels[src]-'a']++;
        result[src]=freq[labels[src]-'a'];
        return freq;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>list[n+1];
        for(auto x:edges)
        {
            list[x[0]].push_back(x[1]);
            list[x[1]].push_back(x[0]);
        }
        vector<int>result(labels.size(),0);
        helper(0,-1,list,labels,result);
        return result;
    }
};