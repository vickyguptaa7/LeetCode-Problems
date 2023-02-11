class Solution {
public:
    
    void helperBfs(int src,int prevColor,int dist,vector<pair<int,int>>list[],
                   vector<int>&result,map<pair<int,int>,int>&edgeFreq)
    {
        result[0]=0;
        queue<vector<int>>que;
        que.push({0,1,-1});
        while(!que.empty())
        {
            int par=que.front()[0];
            int dist=que.front()[1];
            int prevColor=que.front()[2];
            que.pop();
            for(auto [child,cColor]:list[par])
            {
                if(prevColor==cColor||!edgeFreq.count({par,child}))
                    continue;
                
                edgeFreq[{par,child}]--;
                if(edgeFreq[{par,child}]==0)
                    edgeFreq.erase({par,child});
                
                que.push({child,dist+1,cColor});
                result[child]=(result[child]==-1)?dist:min(result[child],dist);
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>list[n];
        map<pair<int,int>,int>edgeFreq;
        for(auto x:redEdges)
        {
            list[x[0]].push_back({x[1],0});
            edgeFreq[{x[0],x[1]}]++;
        }
        for(auto x:blueEdges)
        {
            list[x[0]].push_back({x[1],1});
            edgeFreq[{x[0],x[1]}]++;
        }
        vector<int>result(n,-1);
        helperBfs(0,-1,1,list,result,edgeFreq);
        return result;
    }
};