class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>row(n,0),col(m,0);
        unordered_map<int,pair<int,int>>ump;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ump[mat[i][j]]={i,j};
            }
        }

        for(int i=0;i<arr.size();i++)
        {
            int x=ump[arr[i]].first,y=ump[arr[i]].second;
            row[x]++;
            col[y]++;
            if(row[x]==m||col[y]==n)
                return i;
        }
        return arr.size();
    }
};