class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxH=1,maxV=1,count=hBars.size()?2:1;
        for(int i=1;i<hBars.size();i++)
        {
            if(hBars[i-1]+1==hBars[i])
            {
                count++;
            }
            else
            {
                maxH=max(maxH,count);
                count=2;
            }
        }
        maxH=max(maxH,count);
        count=vBars.size()?2:1;
        for(int i=1;i<vBars.size();i++)
        {
            if(vBars[i-1]+1==vBars[i])
            {
                count++;
            }
            else
            {
                maxV=max(maxV,count);
                count=2;
            }
        }
        maxV=max(maxV,count);
        int sq=min(maxV,maxH);
        return sq*sq;
    }
};