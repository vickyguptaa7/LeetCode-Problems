class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++)
        {
            int x = abs(points[i][0]-points[i-1][0]);
            int y = abs(points[i][1]-points[i-1][1]);
            ans += min(x,y) + abs(min(x,y) - x) + abs(min(x,y) - y);
        }
        return ans;
    }
};