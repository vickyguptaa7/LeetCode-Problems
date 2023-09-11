class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mgrps;
        vector<vector<int>>res;
        for(int i=0;i<groupSizes.size();i++)
        {
            mgrps[groupSizes[i]].push_back(i);
            if(mgrps[groupSizes[i]].size()==groupSizes[i])
            {
                res.push_back(mgrps[groupSizes[i]]);
                mgrps.erase(groupSizes[i]);
            }
        }
        return res;
    }
};