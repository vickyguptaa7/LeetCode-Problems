class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>result;
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    count++;
                else 
                    break;
            }
            result.push_back({count,i});
        }
        sort(result.begin(),result.end());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(result[i].second);
        }
        return ans;
    }
};