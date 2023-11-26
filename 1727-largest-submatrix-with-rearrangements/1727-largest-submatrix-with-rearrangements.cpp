class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int>row(matrix[0].size(),0);
        int res=0;
        for(int i=0;i<matrix.size();i++)
        {
             for(int j=0;j<matrix[i].size();j++)
             {
                 row[j]+=matrix[i][j]?matrix[i][j]:-row[j];
                 // cout<<row[j]<<" ";
             }
            vector<int>temp=row;
            sort(temp.begin(),temp.end(),greater<int>());
            for(int j=0;j<temp.size();j++)
            {
                // cout<<temp[j]<<" ";
                res=max(temp[j]*(j+1),res);
            }
            // cout<<"\n";
        }
        return res;
    }
};