class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>mapping(26);
        for(int i=0;i<s.size();i++)
        {
            mapping[s[i]-'a'].push_back(i);
        }
        map<string,bool>visit;
        int ans=0;
        for(auto word:words)
        {
            int prev=-1;
            bool isFound=true;
            if(visit.count(word))
            {
                ans+=visit[word];
                continue;
            }
            for(int i=0;i<word.size();i++)
            {
                int ch=word[i]-'a';
                auto indx=upper_bound(mapping[ch].begin(),mapping[ch].end(),prev);
                
                if(indx==mapping[ch].end())
                {
                    isFound=false;
                    break;
                }
                else 
                {
                    prev=*indx;
                }
            }
            visit[word]=isFound;
            ans+=isFound;
        }
        return ans;
    }
};