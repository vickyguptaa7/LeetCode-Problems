class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>umap;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            umap[s].push_back(strs[i]);
        }
        vector<vector<string>>result;
        for(auto x:umap)
        {
            result.push_back(x.second);
        }
        return result;
    }
};