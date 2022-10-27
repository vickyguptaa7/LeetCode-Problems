class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>oneCordinate1,oneCordinate2;
        int n=img1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                    oneCordinate1.push_back({i,j});
                if(img2[i][j]==1)
                    oneCordinate2.push_back({i,j});
            }
        }
        int maxOverlap=0;
        map<pair<int,int>,int>mpp;
        for(auto [x1,y1]:oneCordinate1)
        {
            for(auto [x2,y2]:oneCordinate2)
            {
                mpp[{x2-x1,y2-y1}]++;
                maxOverlap=max(maxOverlap,mpp[{x2-x1,y2-y1}]);
            }
        }
        return maxOverlap;
    }
};