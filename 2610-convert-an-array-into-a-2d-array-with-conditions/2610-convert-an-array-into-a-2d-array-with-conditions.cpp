class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(auto &num:nums)
            ump[num]++;
        vector<vector<int>>res;
        for(auto x:ump)
            for(int i=0;i<x.second;i++)
                i==res.size()?res.push_back({x.first}):res[i].push_back(x.first);
            
        return res;
    }
};