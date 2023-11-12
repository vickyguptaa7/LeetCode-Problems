class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(target==source)
            return 0;
        map<int,vector<int>>nroutes;
        for(int i=0;i<routes.size();i++)
        {
            sort(routes[i].begin(),routes[i].end());
            nroutes[i]=routes[i];
        }
        queue<pair<int,int>>que;
        que.push({source,0});
        set<int>visited;
        visited.insert(source);
        while(!que.empty())
        {
            int curr=que.front().first;
            int bus=que.front().second;
            que.pop();
            vector<int>del;
            for(auto &nroute:nroutes)
            {
                auto ele=lower_bound(nroute.second.begin(),nroute.second.end(),curr);
                if(ele!=nroute.second.end()&&*ele==curr)
                {
                    del.push_back(nroute.first);
                    for(auto dest:nroute.second)
                    {
                        if(visited.count(dest))continue;
                        if(dest==target)
                            return bus+1;
                        visited.insert(dest);
                        que.push({dest,bus+1});
                    }
                }
            }
            for(auto d:del)
            {
                nroutes.erase(d);
            }
        }
        return -1;
    }
};