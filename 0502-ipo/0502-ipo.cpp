bool mycomp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second!=b.second)
    {
        return a.second<b.second;
    }
    return a.first>b.first;
}

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>combine;
        for(int i=0;i<profits.size();i++)
        {
            combine.push_back({profits[i],capital[i]});
        }
        sort(combine.begin(),combine.end(),mycomp);
        priority_queue<int>pque;
        int n=capital.size();
        for(int i=0;i<n;i++)
        {
            if(w>=combine[i].second)
            {
                pque.push(combine[i].first);
            }
            else
            {
                if(pque.empty())
                {
                    break;
                }
                w+=pque.top();
                pque.pop();
                k--;
                i--;
                if(k==0)
                    break;
            }
        }
        while(k--&&!pque.empty())
        {
            w+=pque.top();
            pque.pop();
        }
        return w;
    }
};