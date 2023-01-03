class Solution {
public:
    
    void helperDfs(int src,vector<int>list[],
                   vector<int>&inEdgeCnts)
    {
        for(auto curr:list[src])
        {
            inEdgeCnts[curr]-=1;
            if(inEdgeCnts[curr]==0)
            {
                helperDfs(curr,list,inEdgeCnts);
            }

        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>list[numCourses];
        vector<int>inEdgeCnts(numCourses,0);
        for(auto x:prerequisites)
        {
            list[x[1]].push_back(x[0]);
            inEdgeCnts[x[0]]++;
        }
        vector<int>zeroInEdge;
        for(int i=0;i<numCourses;i++)
            if(!inEdgeCnts[i])
                zeroInEdge.push_back(i);
        for(int i=0;i<zeroInEdge.size();i++)
        {
            helperDfs(zeroInEdge[i],list,inEdgeCnts);
        }
        for(auto x:inEdgeCnts)
        {
            if(x!=0)
                return false;
        }
        return true;
    }
};