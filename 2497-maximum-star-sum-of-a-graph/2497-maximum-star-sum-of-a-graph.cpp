class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(k==0)
        {
            return *max_element(vals.begin(),vals.end());
        }
        int n=vals.size();
        vector<pair<int,int>>list[n];
        for(int i=0;i<edges.size();i++)
        {
            list[edges[i][0]].push_back({vals[edges[i][1]],edges[i][1]});
            list[edges[i][1]].push_back({vals[edges[i][0]],edges[i][0]});
        }
        for(auto &x:list)
        {
            sort(x.begin(),x.end(),greater<pair<int,int>>());
        }
        int Max=-1e9;
        for(int i=0;i<n;i++)
        {
            int Sum=vals[i];
            Max=max(Max,Sum);
            int iter=0;
            for(auto x:list[i])
            {
                Sum+=x.first;
                Max=max(Sum,Max);
                iter++;
                if(iter>=k)
                    break;
            }
        }
        return Max;
    }
};