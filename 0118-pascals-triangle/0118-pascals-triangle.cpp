class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal(numRows);
        pascal[0]={1};
        for(int i=1;i<numRows;i++)
        {
            vector<int>row={1};
            for(int j=1;j<i;j++)
            {
                row.push_back(pascal[i-1][j-1]+pascal[i-1][j]);
            }
            row.push_back(1);
            pascal[i]=row;
        }
        return pascal;
    }
};