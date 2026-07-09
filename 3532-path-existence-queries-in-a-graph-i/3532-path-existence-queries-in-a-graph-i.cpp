

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        set<int>sset;
        int val=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]>maxDiff)
            {
                sset.insert(val);
                val=i;
            }
        }
        sset.insert(val);
        vector<bool>res;
        for(auto query:queries)
        {
            int u=query[0],v=query[1];
            res.push_back(sset.upper_bound(u)==sset.upper_bound(v));
        }
        return res;
    }
};