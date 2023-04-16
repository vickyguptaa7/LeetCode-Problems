class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>result(grid[0].size(),1);
        for(auto col:grid)
        {
            for(int i=0;i<col.size();i++)
            {
                bool isNeg=(col[i]<0);
                col[i]=abs(col[i]);
                if(col[i]==0)
                    continue;
                result[i]=max(result[i],(int)isNeg+(int)log10(col[i])+1);
            }
        }
        return result;
    }
};