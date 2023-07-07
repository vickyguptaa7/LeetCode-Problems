class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pque;
        pque.push({points[0][1]-points[0][0],points[0][0]});
        int result=-1e9;
        for(int i=1;i<points.size();i++)
        {
            while(!pque.empty()&&points[i][0]-pque.top().second>k)
                pque.pop();
            if(!pque.empty())
            {
                auto curr=pque.top();
                result=max(result,curr.first+points[i][0]+points[i][1]);
            }
            pque.push({points[i][1]-points[i][0],points[i][0]});
        }
        return result;
    }
};