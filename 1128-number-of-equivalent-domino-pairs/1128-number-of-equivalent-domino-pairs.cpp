class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>freq;
        int count=0;
        for(auto dominoe:dominoes)
        {
            pair<int,int> p={min(dominoe[0],dominoe[1]),max(dominoe[0],dominoe[1])};
            freq[p]++;
            count+=freq[p]-1;
        }
        return count;
    }
};