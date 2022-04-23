class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();
        vector<pair<int,int>>list[n];
        for(int i=0;i<edges.size();i++)
        {
            list[edges[i][0]].push_back({scores[edges[i][1]],edges[i][1]});
            list[edges[i][1]].push_back({scores[edges[i][0]],edges[i][0]});
        }
        for(int i=0;i<n;i++)
        {
            sort(list[i].begin(),list[i].end(),greater());
        }
        int Max=-1;
        for(int i=0;i<edges.size();i++)
        {
            int score=scores[edges[i][0]]+scores[edges[i][1]];
            
            int fedge=-1,sedge=-1;
            for(int j=0;j<list[edges[i][0]].size();j++)
            {
                if(list[edges[i][0]][j].second!=edges[i][1])
                {
                    fedge=list[edges[i][0]][j].second;
                    break;
                }
            }
            for(int j=0;j<list[edges[i][1]].size();j++)
            {
                if(list[edges[i][1]][j].second!=edges[i][0]&&list[edges[i][1]][j].second!=fedge)
                {
                    sedge=list[edges[i][1]][j].second;
                    break;
                }
            }
            if(fedge!=-1&&sedge!=-1)
            {
                int tempans=scores[fedge]+scores[sedge];
                Max=max(Max,score+tempans);
            }
            fedge=-1;
            sedge=-1;
            
            for(int j=0;j<list[edges[i][1]].size();j++)
            {
                if(list[edges[i][1]][j].second!=edges[i][0])
                {
                    fedge=list[edges[i][1]][j].second;
                    break;
                }
            }
            for(int j=0;j<list[edges[i][0]].size();j++)
            {
                if(list[edges[i][0]][j].second!=edges[i][1]&&list[edges[i][0]][j].second!=fedge)
                {
                    sedge=list[edges[i][0]][j].second;
                    break;
                }
            }
            if(fedge!=-1&&sedge!=-1)
            {
                int tempans=scores[fedge]+scores[sedge];
                Max=max(Max,score+tempans);
            }
        }
        return Max;
    }
};