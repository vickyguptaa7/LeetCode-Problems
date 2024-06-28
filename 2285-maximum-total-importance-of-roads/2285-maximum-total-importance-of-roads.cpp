class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);
        for(int i=0;i<roads.size();i++)
        {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++)
        {
            temp[i]={degree[i],i};
        }
        sort(temp.begin(),temp.end());
        vector<int>imp(n);
        for(int i=0;i<temp.size();i++)
        {
            imp[temp[i].second]=i+1;
        }
        long long cost=0;
        for(int i=0;i<roads.size();i++)
        {
             cost+=imp[roads[i][1]]+imp[roads[i][0]];
        }
        return cost;
    }
};