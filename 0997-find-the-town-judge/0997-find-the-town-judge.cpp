class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0);
        vector<int>out(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            in[trust[i][0]]++;
            out[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++)if(!in[i]&&out[i]==n-1)return i;
        return -1;
    }
};