class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<string,vector<string>>mmp;
        for(auto x:strs)
        {
            string s=x;
            sort(s.begin(),s.end());
            mmp[s].push_back(x);
        }
        for(auto x:mmp)
        {
            res.push_back(x.second);
        }
        return res;
    }
};