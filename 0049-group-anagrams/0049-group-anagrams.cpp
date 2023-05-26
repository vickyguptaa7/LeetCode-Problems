class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>group;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            group[temp].push_back(i);
        }
        vector<vector<string>>result;
        for(auto g:group)
        {
            vector<string>row;
            for(int i=0;i<g.second.size();i++)
            {
                row.push_back(strs[g.second[i]]);
            }
            result.push_back(row);
        }
        return result;
    }
};