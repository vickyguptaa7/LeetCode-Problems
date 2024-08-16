class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn1=1e9,mn2=1e9,mni1=-1,mni2=-1;
        int mx1=-1e9,mx2=-1e9,mxi1=-1,mxi2=-1;
        for(int i=0;i<arrays.size();i++)
        {
            if(mn1>arrays[i][0])
            {
                mn2=mn1;
                mn1=arrays[i][0];
                mni2=mni1;
                mni1=i;
            }
            else if(mn2>arrays[i][0])
            {
                mn2=arrays[i][0];
                mni2=i;
            }
            
            if(mx1<arrays[i].back())
            {
                mx2=mx1;
                mx1=arrays[i].back();
                mxi2=mxi1;
                mxi1=i;
            }
            else if(mx2<arrays[i].back())
            {
                mx2=arrays[i].back();
                mxi2=i;
            }
        }
        return mni1!=mxi1?mx1-mn1:max(mx1-mn2,mx2-mn1);
    }
};