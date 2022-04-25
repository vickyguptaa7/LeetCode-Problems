class Solution {
public:
    
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>>rect(101);
        for(auto &x:rectangles)
        {
            rect[x[1]].push_back(x[0]);
        }
        
        for(auto &x:rect)
        {
            sort(x.begin(),x.end());
        }
        
        vector<int>res;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0],y=points[i][1];
            int tempans=0;
            for(int j=y;j<=100;j++)
            {
            int low=0,high=rect[j].size()-1;
            int ans=rect[j].size();
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(rect[j][mid]>=x)
                {
                    high=mid-1;
                    ans=mid;
                }
                else
                {
                    low=mid+1;
                }
            }
                tempans+=rect[j].size()-ans;
            }
            res.push_back(tempans);
        }
        return res;
    }
};