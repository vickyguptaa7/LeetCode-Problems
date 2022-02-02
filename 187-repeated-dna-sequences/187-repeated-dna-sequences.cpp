class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>result;
        int len=s.length();
        
        if(len<=10)return result;
        
        unordered_map<string,int>umap;
        
        int left=0,right=0;
        string pat;
        while(right<len)
        {
            while(10>right-left)
            {
                pat+=s[right];
                right++;
            }
            umap[pat]++;
            pat=pat.substr(1);
            left++;
        }
        for(auto &x:umap)
        {
            if(x.second>1)
            result.push_back(x.first);
        }
        return result;
    }
};