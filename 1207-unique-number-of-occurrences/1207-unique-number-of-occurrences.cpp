class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>freq(2e3+4,0);
        for(auto &x:arr)freq[x+1e3+2]++;
        sort(freq.begin(),freq.end());
        for(int i=1;i<freq.size();i++)
        {
            if(freq[i]==0)continue;
            if(freq[i]==freq[i-1])
                return false;
        }
        return true;
    }
};