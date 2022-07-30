class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>freq,temp;
        for(int i=0;i<words2.size();i++)
        {
            string word=words2[i];
            for(int j=0;j<word.size();j++)
            {
                temp[word[j]]++;
            }
            for(auto x:temp)
            {
                if(!freq.count(x.first))
                {
                    freq[x.first]=x.second;
                }
                else if(freq[x.first]<x.second)
                {
                    freq[x.first]=x.second;
                }
            }
            temp.clear();
        }
        vector<string> result;
        for(int i=0;i<words1.size();i++)
        {
            string word=words1[i];
            for(int j=0;j<word.size();j++)
            {
                temp[word[j]]++;
            }
            bool isFind=true;
            for(auto x:freq)
            {
                if(temp[x.first]<x.second)
                {
                    isFind=false;
                    break;
                }
            }
            if(isFind)
                result.push_back(word);
            temp.clear();
        }
        
        return result;
    }
};