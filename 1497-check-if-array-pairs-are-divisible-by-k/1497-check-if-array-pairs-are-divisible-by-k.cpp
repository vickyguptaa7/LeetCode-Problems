class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>freq;
        for(auto &x:arr)
            freq[(x%k+k)%k]++;
        for(auto &x:freq)
        {
            if((x.first)%k!=(k-x.first)%k)
            {
                if(x.second!=freq[k-x.first])
                    return false;
            }
            else
            {
                if(x.second&1)
                    return false;
            }
        }
        return true;
    }
};