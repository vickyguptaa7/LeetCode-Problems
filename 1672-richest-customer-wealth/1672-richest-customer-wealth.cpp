class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth=0;
        int n=accounts.size(),m=accounts[0].size();
        for(int i=0;i<n;i++)
        {
            int wealth=accumulate(accounts[i].begin(),accounts[i].end(),0);
            max_wealth=max(max_wealth,wealth);
        }
        return max_wealth;
    }
};