class Solution {
public:
    int maximizeSquareArea(int n, int m, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back({1});
        hFences.push_back({n});
        vFences.push_back({1});
        vFences.push_back({m});
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int>hset;
        for(int i=0;i<hFences.size();i++)
        {
            for(int j=i+1;j<hFences.size();j++)
            {
                hset.insert(hFences[j]-hFences[i]);
            }
        }
        int res=-1,mod=1e9+7;
        for(int i=0;i<vFences.size();i++)
        {
            for(int j=i+1;j<vFences.size();j++)
            {
                int val=vFences[j]-vFences[i];
                if(hset.count(val))
                    res=max(res,val);
            }
        }
        return res==-1?res:(res*1ll*res)%mod;
    }
};