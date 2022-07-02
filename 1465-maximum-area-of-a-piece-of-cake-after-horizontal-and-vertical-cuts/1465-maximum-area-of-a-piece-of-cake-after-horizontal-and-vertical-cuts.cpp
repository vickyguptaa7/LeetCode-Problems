class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(),vCuts.end());
        
        int hMax=hCuts[0],vMax=vCuts[0];
        
        for(int i=1;i<hCuts.size();i++)
        {
            hMax=max(hMax,hCuts[i]-hCuts[i-1]);
        }
        hMax=max(hMax,h-hCuts.back());
        
        for(int i=1;i<vCuts.size();i++)
        {
            vMax=max(vMax,vCuts[i]-vCuts[i-1]);
        }
        vMax=max(vMax,w-vCuts.back());
        long long mod=1e9+7;
        return ((long long)hMax*vMax)%mod;
    }
};