class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>freq;
        for(auto x:arr)
        {
            freq[x]++;
        }
        set<int>oset;
        for(auto x:freq)
        {
            oset.insert(x.second);
        }
        if(freq.size()==oset.size())
            return true;
        return false;
    }
};