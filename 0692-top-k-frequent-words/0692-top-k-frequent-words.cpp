class comparator
{
    public:
    bool operator()(pair<int,string>&a,pair<int,string>&b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        return a.second<b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(auto x:words)
        {
            freq[x]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator>pque;
        for(auto x:freq)
        {
            if(pque.size()<k)
            {
                pque.push({x.second,x.first});
            }
            else 
            {
                pque.push({x.second,x.first});
                pque.pop();
            }
        }
        vector<string>res;
        while(!pque.empty()&&k)
        {
            k--;
            res.push_back(pque.top().second);
            pque.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};