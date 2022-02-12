class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)res.push_back(i);
        }
        return res;
    }
};