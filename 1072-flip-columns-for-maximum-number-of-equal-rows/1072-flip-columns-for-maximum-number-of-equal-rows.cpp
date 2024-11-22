class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>mp;
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            string res="",comp="";
            for(int j=0;j<matrix[0].size();j++)
            {
                res+=(matrix[i][j]&1)?"1":"0";
                comp+=(matrix[i][j]&1)?"0":"1";
            }
            mp[res]++;
            mp[comp]++;
            ans=max(ans,max(mp[res],mp[comp]));
        }
        return ans;
    }
};