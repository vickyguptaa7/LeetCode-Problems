class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int>beauty;
        for(int i=0;i<items.size();i++)
        {
            beauty[items[i][0]]=max(items[i][1],beauty[items[i][0]]);
        }
        int prev=0;
        for(auto &x:beauty)
        {
            x.second=max(x.second,prev);
            prev=x.second;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            auto curr=beauty.upper_bound(queries[i]);

            if(curr==beauty.begin())
            {
                ans.push_back(0);
            }
            else
            {
                --curr;
                ans.push_back(curr->second);
            }
        }
        return ans;
    }
};