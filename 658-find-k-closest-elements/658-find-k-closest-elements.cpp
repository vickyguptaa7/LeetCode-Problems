class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pque;
        for(auto num:arr)
        {
            pque.push({abs(x-num),num});
            if(pque.size()>k)pque.pop();
        }
        vector<int>res;
        while(!pque.empty())
        {
            res.push_back(pque.top().second);
            pque.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};