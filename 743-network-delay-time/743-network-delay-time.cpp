class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>list[n+1];
        for(int i=0;i<times.size();i++)
        {
            list[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int>distance(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        
        que.push({0,k});
        distance[k]=0;
        int timeReq=0;
        
        while(!que.empty())
        {
            int src=que.top().second;
            int time=que.top().first;
            que.pop();
            for(auto curr:list[src])
            {
                if(curr.second+time<distance[curr.first])
                {
                    // cout<<curr.first<<"\n";
                    que.push({curr.second+time,curr.first});
                    distance[curr.first]=curr.second+time;
                }
                    
            }
        }
        for(int i=1;i<n+1;i++)
        {
            if(distance[i]==1e9)return -1;
            timeReq=max(timeReq,distance[i]);
        }
        return timeReq;
    }
};