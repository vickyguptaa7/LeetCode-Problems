class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>res;
        for(int i=0;i<words.size();i++)
        {
            set<char>oset;
            map<char,int>omap;
            string word=words[i];
            if(word.size()!=pattern.size())continue;
            bool isTrue=true;
            for(int i=0;i<word.size();i++)
            {
                if(omap.count(pattern[i])&&omap[pattern[i]]!=word[i])
                {
                    isTrue=false;
                    break;
                }
                if(oset.count(word[i])&&!omap.count(pattern[i]))
                {
                    isTrue=false;
                    break;
                }
                omap[pattern[i]]=word[i];
                oset.insert(word[i]);
            }
            if(isTrue)
                                 {
                                     res.push_back(word);
                                 }
        }
                                 return res;
    }
};