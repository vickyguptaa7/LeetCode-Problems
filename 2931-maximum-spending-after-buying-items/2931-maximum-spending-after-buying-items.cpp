class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pque;
        int indx=values[0].size()-1;
        int div=1e5;
        for(int i=0;i<values.size();i++)
        {
            pque.push({values[i][indx],indx+div*i});
        }
        long long spending=0,day=1;
        while(!pque.empty())
        {
            int price=pque.top().first;
            int indx=pque.top().second%div;
            int row=pque.top().second/div;
            pque.pop();
            spending+=day*price;
            day++;            
            if(indx==0)continue;
            pque.push({values[row][indx-1],indx-1+row*div});
        }
        return spending;
    }
};