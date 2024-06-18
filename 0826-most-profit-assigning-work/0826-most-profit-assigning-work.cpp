class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>combine;
        for(int i=0;i<profit.size();i++)
        {
            combine.push_back({difficulty[i],profit[i]});
        }
        sort(combine.begin(),combine.end());
        int p=0,curr=0,cost=0;
        sort(worker.begin(),worker.end());
        for(int i=0;i<combine.size();i++)
        {
            if(worker[curr]<combine[i].first)
            {
                curr++;
                p+=cost;
                if(curr>=worker.size())
                    break;
                i--;
            }
            else
            {
                cost=max(cost,combine[i].second);
            }
        }
        p+=((int)worker.size()-curr)*cost;
        return p;
    }
};