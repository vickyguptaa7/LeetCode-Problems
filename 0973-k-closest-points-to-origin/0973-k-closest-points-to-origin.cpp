class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pque;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0],y=points[i][1];
            pque.push({x*x+y*y,i});
            if(pque.size()>k)
                pque.pop();
        }
        vector<vector<int>>result;
        while(!pque.empty())
        {
            result.push_back(points[pque.top().second]);
            pque.pop();
        }
        return result;
    }
};