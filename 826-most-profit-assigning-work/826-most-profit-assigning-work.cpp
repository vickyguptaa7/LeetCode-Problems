class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>combine;
        for(int i=0;i<profit.size();i++)
            combine.push_back({difficulty[i],profit[i]});
        sort(combine.begin(),combine.end());
        int itr=0,res=0,Max=0;
        for(int i=0;i<worker.size();i++)
        {
            while(itr<worker.size()&&combine[itr].first<=worker[i])
            {
                itr++;
                Max=max(Max,combine[itr-1].second);
            }
            res+=Max;
        }
        return res;
        
    }
};