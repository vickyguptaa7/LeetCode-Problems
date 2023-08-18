class Solution {
public:
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>list[n];
        for(auto& road:roads)
        {
            list[road[0]].push_back(road[1]);
            list[road[1]].push_back(road[0]);
        }
        int mxRank=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool isPresent=false;
                for(auto child:list[i])
                {
                    if(child==j)
                    {
                        isPresent=true;
                        break;
                    }
                }
                mxRank=max(mxRank,(int)list[i].size()+(int)list[j].size()-isPresent);
            }
        }
        return mxRank;
    }
};