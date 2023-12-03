class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for(int i=1;i<points.size();i++)
        {
            int mn=min(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
            int mx=max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
            time+=mn+(mx-mn);
        }
        return time;
    }
};