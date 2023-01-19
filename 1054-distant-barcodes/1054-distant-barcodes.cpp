class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        map<int,int>freq;
        for(auto x:barcodes)
            freq[x]++;
        priority_queue<pair<int,int>>pque;
        for(auto x:freq)
        {
            pque.push({x.second,x.first});
        }
        vector<int>result(n);
        int iter=0;
        while(pque.size()>1)
        {
            auto curr1=pque.top();
            pque.pop();
            auto curr2=pque.top();
            pque.pop();
            result[iter++]=curr1.second;
            result[iter++]=curr2.second;
            curr1.first--;
            curr2.first--;
            if(curr1.first!=0)
            {
                pque.push({curr1.first,curr1.second});
            }
            if(curr2.first!=0)
            {
                pque.push({curr2.first,curr2.second});
            }
        }
        if(!pque.empty())
            result[iter]=pque.top().second;
        return result;
    }
};