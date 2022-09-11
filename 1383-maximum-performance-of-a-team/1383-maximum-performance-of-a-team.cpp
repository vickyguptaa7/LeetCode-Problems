typedef pair<int,int> ppi;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<ppi>combine;
        for(int i=0;i<n;i++)
        {
            combine.push_back({efficiency[i],speed[i]});
        }
        sort(combine.rbegin(),combine.rend());
        
        priority_queue<int,vector<int>,greater<int>>pque;
        
        long long result=0,runSum=0;
        for(auto &curr:combine)
        {
            runSum+=curr.second;
            pque.push(curr.second);
            
            if(pque.size()>k)
            {
                runSum-=pque.top();
                pque.pop();
            }
            
            result=max(result,runSum*curr.first);
        }
        int mod=1e9+7;
        return result%mod;
    }
};