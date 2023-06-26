class Compare {
    public:
       bool operator()(pair<int,int>& a, pair<int,int>& b){
         return (a.first>b.first)||(a.first==b.first&&a.second>b.second);
      }
};
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pque;
        int n=costs.size();
        for(int i=0;i<candidates;i++)pque.push({costs[i],i});
        for(int i=max(n-candidates,candidates);i<n;i++)pque.push({costs[i],i});
        int left=candidates,right=max(n-candidates-1,candidates-1);
        long long cost=0;
        while(k--)
        {
            auto curr=pque.top();
            pque.pop();
            cost+=curr.first;
            if(left>right)continue;
            if(curr.second<left)
            {
                pque.push({costs[left],left});
                left++;
            }
            else 
            {
                pque.push({costs[right],right});
                right--;
            }
        }
        return cost;
    }
};