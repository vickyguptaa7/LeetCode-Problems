class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>result;
        sort(potions.begin(),potions.end());
        int n=potions.size();
        for(auto x:spells)
        {
            long long val=ceil(success/(long double)x);
            int indx=lower_bound(potions.begin(),potions.end(),
                                 val)-potions.begin();

            result.push_back(n-indx);
        }
        return result;
    }
};