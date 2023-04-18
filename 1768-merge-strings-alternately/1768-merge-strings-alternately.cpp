class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int it1=0,it2=0;
        while(it1<word1.size()||it2<word2.size())
        {
            if(it1<word1.size())
            {
                res+=word1[it1++];
            }
            if(it2<word2.size())
            {
                res+=word2[it2++];
            }
        }
        return res;
    }
};