class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        
        map<char,int>mp1,mp2;
        for(auto x:word1)
            mp1[x]++;
        for(auto x:word2)
            mp2[x]++;
        
        vector<int>v1,v2;
        for(auto x:mp1)
        {
            if(!mp2.count(x.first))
                return false;
            v1.push_back(x.second);
        }
        
        for(auto x:mp2)
        {
            if(!mp1.count(x.first))
                return false;
            v2.push_back(x.second);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
                
        
        if(v1!=v2)
            return false;
        
        return true;
    }
};