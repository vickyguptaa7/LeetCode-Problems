class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int size=(1<<(int)requests.size());
        vector<int>net(n+1,0);
        int mxCntr=0;
        for(int i=0;i<size;i++)
        {
            int cntr=0;
            for(int j=0;j<requests.size();j++)
            {
                if((i&(1<<j)))
                {
                    cntr++;
                    net[requests[j][0]]--;
                    net[requests[j][1]]++;
                }
            }
            bool isNetZero=true;
            for(int i=0;i<=n;i++)
            {
                if(net[i]!=0)
                {
                    isNetZero=false;
                }
                net[i]=0;
            }
            if(isNetZero)
                mxCntr=max(cntr,mxCntr);
        }
        return mxCntr;
    }
};