class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp>pque;
        int n=points.size();
        for(int i=0;i<k;i++)
        {
            int _x=points[i][0];
            int _y=points[i][1];
            int dist=_x*_x+_y*_y;
            pque.push({dist,{_x,_y}});
        }
        for(int i=k;i<n;i++)
        {
            int _x=points[i][0];
            int _y=points[i][1];
            int dist=_x*_x+_y*_y;
            if(dist<pque.top().first)
            {
                pque.pop();
                 pque.push({dist,{_x,_y}});
            }
        }
        vector<vector<int>>res;
        while(!pque.empty())
        {
            int _x=pque.top().second.first;
            int _y=pque.top().second.second;
            res.push_back({_x,_y});
            pque.pop();
        }
        return res;
    }
};