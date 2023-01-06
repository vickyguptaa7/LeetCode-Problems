class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPointOnLine=1;
        for(int i=0;i<points.size();i++)
        {
            map<pair<int,int>,int>freq;
            for(int j=i+1;j<points.size();j++)
            {
                int x=points[i][0]-points[j][0];
                int y=points[i][1]-points[j][1];
                int gcd=__gcd(x,y);
                freq[{x/gcd,y/gcd}]++;
            }
            for(auto x:freq)
            {
                maxPointOnLine=max(maxPointOnLine,x.second+1);
            }
        }
        return maxPointOnLine;
    }
};