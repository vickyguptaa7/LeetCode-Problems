class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto &x:grid)
        {
            sort(x.begin(),x.end());
        }
        int ans=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<c;i++)
        {
            int mx=-1e9;
            for(int j=0;j<r;j++)
            {
                mx=max(mx,grid[j][i]);
            }
            ans+=mx;
        }
        return ans;
    }
};