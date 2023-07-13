class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mxPoints=1;
        for(int i=0;i<points.size();i++)
        {
            map<pair<int,int>,int>freq;
            for(int j=i+1;j<points.size();j++)
            {
                int _x=points[i][0]-points[j][0];
                int _y=points[i][1]-points[j][1];
                int gcd=__gcd(_x,_y);
                freq[{_x/gcd,_y/gcd}]++;
            }
            for(auto x:freq)
                mxPoints=max(mxPoints,x.second+1);
        }
        return mxPoints;
    }
};