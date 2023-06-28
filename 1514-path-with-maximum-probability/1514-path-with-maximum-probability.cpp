class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>list[n];
        for(int i=0;i<edges.size();i++)
        {
            list[edges[i][0]].push_back({edges[i][1],succProb[i]});
            list[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pque;
        pque.push({1,start});
        vector<double>prob(n,0);
        prob[start]=1;
        while(!pque.empty())
        {
            auto curr=pque.top();
            pque.pop();
            // cout<<curr.second<<"\n";
            for(auto child:list[curr.second])
            {
                // cout<<prob[child.first]<<" "<<curr.first*child.second<<"\n";
                if(prob[child.first]<curr.first*child.second)
                {
                    prob[child.first]=curr.first*child.second;
                    pque.push({prob[child.first],child.first});
                }
            }
        }
        return prob[end];
    }
};