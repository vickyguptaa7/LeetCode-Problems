class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>freq(501,0);
        
        for(auto &x:nums)
            freq[x]++;
        
        for(auto &x:freq)
            if(x&1)
                return false;

        return true;
    }
};