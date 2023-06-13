class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int pairCount=0,n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool isEqual=true;
                for(int k=0;k<n;k++)
                {
                    if(grid[i][k]!=grid[k][j])
                    {
                        isEqual=false;
                        break;
                    }
                }
                pairCount+=isEqual;
            }
        }
        return pairCount;
    }
};