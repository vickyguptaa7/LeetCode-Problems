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
                vector<int>vec=mapping[word[i]-'a'];
                auto indx=upper_bound(vec.begin(),vec.end(),prev);
                
                if(indx==vec.end())
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