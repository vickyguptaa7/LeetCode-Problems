bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[1]!=b[1])
        return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),mycomp);
        int arrowCnt=0,size=points.size();
        for(int i=0;i<size;i++)
        {
            int y=points[i][1];
            int iter=i;
            while(iter<size&&y>=points[iter][0]&&y<=points[iter][1])
                iter++;
            iter--;
            i=iter;
            arrowCnt++;
        }
        return arrowCnt;
    }
};