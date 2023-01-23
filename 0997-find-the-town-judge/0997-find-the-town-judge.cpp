class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>list[n+1];
        vector<int>inEdge(n+1,0);
        for(auto x:trust)
        {
            list[x[0]].push_back(x[1]);
            inEdge[x[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(list[i].empty()&&inEdge[i]==n-1)
                return i;
        }
        return -1;
    }
};