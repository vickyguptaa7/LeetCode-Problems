bool mycomp(vector<int> &a1, vector<int> &a2)
{
    if (a1[0] != a2[0])
        return a1[0] < a2[0];
    else
        return a1[1] > a2[1];
}

class Solution
{
    public:
    
    int maxEnvelopes(vector<vector < int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), mycomp);

        int n = envelopes.size();

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int lwr=lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
            if(lwr==res.size())res.push_back(envelopes[i][1]);
            res[lwr]=envelopes[i][1];
        }
        return res.size();
    }
};