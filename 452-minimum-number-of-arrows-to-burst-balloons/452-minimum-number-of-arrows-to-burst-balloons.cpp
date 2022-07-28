bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[1]!=b[1])
    {
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),mycomp);
        int res=1,prev=points[0][1],n=points.size();
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>prev)
            {
                prev=points[i][1];
                res++;
            }
        }
        return res;
    }
};